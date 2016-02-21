//bb.c
// cocacola
// Ultra ReEdit

#include <room.h>
#include <ansi.h>
inherit ROOM;

int Maxperson,minperson;
int allow_leave,allow_start,startbp=0,stopbp=0;
int Max1,Max2,Max3,Max4,Max5,Max6;
int Realmode=0;
int NowLea=-1,jinhua=0;
string roomname;
object* member,leader,dutang1,dutang2,winner;
object here=this_object();
int is_busy=0;

void do_yao2(object ob, string re1,int getaward,int getscore,string dest);
void do_yao1(object ob, string re,string re1, int getaward,
	int getscore, string dest);
int  getnewzy();
void game_over(int i);
int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
int do_yao();
int getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
void pass_token(int,int);
int startreal();
int stopreal();
int dkickout(string arg);
string look_sign();

int check_member()
{
    int i,j=0;
    if(!member) return 0;
    i=sizeof(member);
    while(i--) {
	if(!member[i]) {
	    member=member[0..(i-1)]+member[(i+1)..];
	    continue;
	}
	if(!interactive(member[i])) continue;
	if(query_idle(member[i])>240) continue;
	if(environment(member[i])!=here) continue;
	j++;
    }
    return j;
}

void create()
{
        Maxperson=12;
	minperson=4;
	allow_leave=1;
	allow_start=0;
	Max1=32;//一秀的个数
	Max2=16;
	Max3=8;
	Max4=4;
	Max5=2;
	Max6=1;
	Realmode=0;//实际上有没有奖品.
	roomname="好运博饼室";
		//** 不同的房间有不同的名字
	set("no_fight","1");
	set("no_magic","1");
	set("short","好运博饼室");
	set("long", @LONG
这里是一处很幽静的地方，有一石桌和若干石凳，四周是一片绿色的树林，隐约
还能闻到桂花的香味，看着边上那条静静流着的小溪，你心中不禁泛起逝者如斯的感
慨，在这微微的伤感中，轻叹一声：又到中秋了．．．
    这时你才发现石桌上刻着一些小字(word)．．．
LONG);

	set("item_desc",(["word":(:look_sign:)]));
  	set("exits",
  	(["south":"/d/city/kezhan",
	  "north":__DIR__"bobing1"]));
	//**本处应改为实际的出口

	set("valid_startroom", 1);
	// This enables players to save this room as their startroom.

	set("no_clean_up",1);
	setup();
	
//        call_other("/obj/board/bobing.c","???");
	//**请加入一个留言板
}


void init(){
	add_action("fjoin","join");		//加入博饼
	add_action("fleave","leave");		//离开
	add_action("fjoiner","joiner");		//查看加入者
	add_action("fyao","bp");		//博饼	
	add_action("fstartbp","startbp");	//开始博饼
	add_action("fstopbp","stopbp");		//结束博饼
	add_action("startreal","start");	//巫师决定正式开始
	add_action("stopreal","stop");		//巫师决定结束博饼
	add_action("dkickout","kout");	//强制某人退出博饼
	add_action("fnextbp","nextbp");		//强迫跳过某人.
}

void give_cake(object ob)
{
    object cake;
    
    if(!ob) return;
    cake=new(__DIR__"obj/mooncake");
    message_vision("$N得到了一块精美的$n！\n",ob,cake);
    if(!cake->move(ob))
        cake->move(environment(ob));
}

int fstopbp()
  {
  object *play,ob;
//  if(is_busy && !wizardp(this_player())) return 0;
//  if (!wizardp(this_player()))return 0;
  if (startbp==0)return notify_fail("博饼已经结束了\n");
  play=users();
  tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
       "============\n"+roomname+"的博饼结束了\n"NOR);
  startbp=0;
  return 1;
  
  }

int fstartbp()
  {
  object *play,ob;

  if (startbp==1) return notify_fail("博饼已经开始呢\n");  	
  play=users();
  tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
       "============\n"+roomname+"的博饼现在开始了\n"NOR);
  startbp=1;
  return 1;
  }

int fnextbp()
 {
 if (wizardp(this_player()))
   {
   if (NowLea<0) return notify_fail("还没有人开始博饼呢\n");
   pass_token(NowLea+1,0);
   return 1;
   }
 else
   {
   return 0;
   } 
 }

int dkickout(string arg)			
  {
  object ob;
  if (!wizardp(this_player()))return 0;
  if(!arg) return notify_fail("你要踢谁出去？\n");
  if (!objectp(ob=present(arg))) return notify_fail("你要踢谁出去？\n");
  if (!query_member(ob)) return notify_fail("此人并没有博饼！\n"); 
  delete_member(ob);
  Maxperson++;
  tell_room(environment(this_player()),HIY+ob->query("name")+"被踢出去了\n"NOR);
}

string look_sign()
{
string restring;
//if (Realmode) {
restring="这里是"+roomname+"如果你在测试过程中发现有什么漏洞，请联系\n"+
"Ultra或Cocacola(larnk@usa.net)。游戏方法如下:\n"+
"  先要join加入到博饼游戏中。(用joiner可以看到已经加入的玩家情况)\n"+
"  在轮到你丢时，用bp命令就可以了。(现在还没有奖品，:)\n"+
"  在离开前要先用leave命令才能离开。\n"+
"  另外，公布一下这个博饼游戏的规则(如觉有不对或不妥之处，请联系Ultra\n"+
"或Cocacola)\n"+
"  几个人轮流丢6个股子（我没法找到sai这个字），大小顺序排列如下:\n"+
"  6个四        六浮红（通吃）另外奖励\n"+
"  6个其它的    六浮黑  \n"+
"  4个四加两个一 状元插金花  \n"+
"  5个4         五  红\n"+
"  5个其他的    五  主\n"+
"  4个4	       状元   1个 状元以上加潜能10\n"+
"  1-6各一	对堂  2个 加潜能8\n"+
"  3个4         三红  4个 加潜能4\n"+	
"  4个一样的(除4外) 四进  8个  加潜能3\n"+
"  2个4         二举	16个   加潜能2\n"+
"  1个4 	       一秀 32个 加潜能1\n"+
"(感谢Ocean告诉我博饼的基本规则)\n"+
"另外，状元归谁是比大小的，谁得到最后的状元，将得到额外的奖品。\n";
/*}
else{
restring="这里是"+roomname+"现在游戏正式进行,你将得到很丰厚的\n"+
"奖品(如果你运气好的话，一夜之间你就是一代大侠了)\n"+
"如果你在测试过程中发现有什么漏洞，请联系\n"+
"Ultra或Cocacola(larnk@usa.net)。游戏方法如下:\n"+
"游戏规则如下:\n"+
"  先要join加入到博饼游戏中。(用joiner可以看到已经加入的玩家情况)\n"+
"  在轮到你丢时，用bp命令就可以了。\n"+
"  在离开前要先用leave命令才能离开。\n"+
"  大小顺序排列如下:\n"+
"  6个四        六浮红（通吃）\n"+
"  6个其它的    六浮黑  \n"+
"  4个四加两个一 状元插金花  \n"+
"  5个4         五  红\n"+
"  5个其他的    五  主\n"+
"  4个4	       状元   1个 \n"+
"  1-6各一	对堂  2个 \n"+
"  3个4         三红  4个 \n"+	
"  4个一样的(除4外) 四进  8个  \n"+
"  2个4         二举	16个   \n"+
"  1个4 	       一秀 32个 \n"+
"(感谢Ocean告诉我博饼的基本规则)\n"+
"另外，状元归谁是比大小的，谁得到最后的状元，将得到额外的奖品。\n";
**状元的附加奖励可以另外,同时你看一下那些奖励可以改动就改吧.
}
*/
return restring;
}

int startreal()
  {
  object ob;
  object* pl;
  ob=this_player();
  if (wizardp(ob))
    {
    Realmode=1;
    pl=users();
    tell_room(here,"\n"+HIY+ob->query("name")+"宣布："+roomname+"的百宝囊正式打开，奖品立即兑现！\n"NOR);
    return 1;
    }
  return 0;
 }

int stopreal()
  {
  object ob;
  object* pl;
  ob=this_player();
  if (wizardp(ob))
    {
    Realmode=0;
    pl=users();
    tell_room(here,"\n"+HIY+ob->query("name")+"宣布:"+roomname+
	    "仅用于测试和娱乐,百宝囊收掉了！\n"NOR);
    return 1;
    } 
  return 0;
  }


void pass_token(int index,int passmode)
{
  int me,i,passok;
  me=index-1;
  allow_leave=0;
  passok=0;
  leader=0;
  NowLea=-1;
//  if( passmode==0)
//    {
    for(i=0;i<sizeof(member)-1;i++,index++)
      {
    //  index=index+i;
      if (index>=sizeof(member)) index=index-sizeof(member);
      if(!member[index]) {
	  member=member[0..(index-1)]+member[(index+1)..];
	  continue;
      }
      if(!interactive(member[index])) continue;
      if(query_idle(member[index])>240) continue;
      if(environment(member[index])!=here) continue;

	passok=1;
	leader=member[index];
	break;
      }
    if ((!passok)||(sizeof(member)<minperson))
       {
       allow_start=0;
       tell_room(here,"陪你玩的人还不够，等人来了吧。\n");
       return;
       }
    else tell_room(here,"现在轮到"+leader->query("name")+"掷了。\n");	
//    }
/*
  if(passmode==1)			//
    {
    if (index>=sizeof(member)) index=index-sizeof(member);
    passok=1;
    leader=member[index];
    }
    */
  allow_leave=1;
  NowLea=index;
}

int fyao()		//开始摇股子
  {
  object ob;
  int i,j,k;
  ob=this_player();
  i=query_member(ob);

  if(is_busy) return notify_fail("别着急，再等一等！\n");

  if(check_member()>=minperson) allow_start=1;

  if (allow_start )	//如果人数够的话allow_start>0
    {
    if (startbp==0)return notify_fail("博饼还没有开始呢\n");
    if (i>0)		//是否已经加入到游戏中了
      {
      // check leader.
      if(!leader) leader=ob;
      if(!interactive(leader)) leader=ob;
      if(query_idle(leader)>240) leader=ob;
      if(environment(leader)!=here) leader=ob;
      NowLea=query_member(leader)-1;

      if(ob==leader)	//是否轮到你了
        {
	    do_yao();
	    return 1;
//   	if (do_yao()) return 1;	//开始摇
//	pass_token(i,0);//让下一个摇
//	return 1;
 	}
      else notify_fail("还没轮到你呢，瞎嚷嚷什么呀！\n");
      }
    else notify_fail("你应该先参加进去才能和大家一起播饼。\n");
    }
  else notify_fail("现在人还不够，再等等吧。\n");
  }

int fjoiner()		//查看加入游戏的人
  {		
  object ob;
  int i;
  ob=this_player();
  if (!arrayp(member)||sizeof(member)==0) 
	notify_fail("没有人在这里博饼。\n");
  else
    {
    printf("玩家          最高奖       一秀  二举  四进  三红  对堂  状元\n");
    printf("=============================================================\n");
    for(i=0;i<sizeof(member);i++)
      {
	  if(!member[i]) continue;

      printf("%-14s%-11s%6d%6d%6d%6d%6d%6d\n",
      member[i]->query("name"),member[i]->query_temp("cocacola/dest"),
      member[i]->query_temp("cocacola/g1"),member[i]->query_temp("cocacola/g2"),
      member[i]->query_temp("cocacola/g3"),member[i]->query_temp("cocacola/g4"),
      member[i]->query_temp("cocacola/g5"),member[i]->query_temp("cocacola/g6"),);
      }
    printf("=============================================================\n");
    printf("%-14s%-11s%6d%6d%6d%6d%6d%6d\n",
	    "总计","",32-Max1,16-Max2,8-Max3,4-Max4,2-Max5,1-Max6); 
    printf("=============================================================\n");
    if(winner)
      printf("现在的状元获得者是：%s\n",winner->query("name"));
    if(leader)
      printf("现在轮到%s掷了。\n",leader->query("name"));
    if(check_member()==0)  game_over(1);
    return 1;
    }
  }

int fleave()		//离开游戏
  {
  object ob;
  object nil;
  ob=this_player();
//  if (allow_leave==0 || is_busy) return notify_fail("暂时无法退出\n");
  if (is_busy) return notify_fail("暂时无法退出\n");
  if (leader && leader!=ob) return notify_fail("必须是你博的时候才可以退出\n");
  if (query_member(ob)) 
    {
    pass_token(query_member(ob),1);
    message_vision("$N离开了大家不玩博饼了\n",ob);
    Maxperson++;
    delete_member(ob);
    if(ob==winner) winner=0;
    return 1;
    }
  else return notify_fail("你并没有加入到游戏中啊！\n");
  return 1;
  }

int fjoin()		//参加到游戏中
  {
  object ob;
  ob=this_player();
  if(check_member()==0)  game_over(1);

  if (startbp==1)return notify_fail("博饼已经开始了,你不能再加入了\n");
  if (!(query_member(ob))) 
    {
    if (Maxperson>0) 
      {
      message_vision("$N来这里和大家一起玩博饼．．．\n",ob);
      Maxperson--;
      add_member(ob);
      ob->delete_temp("cocacola");	//追加此句为了清楚本来的数据
      ob->set_temp("cocacola/dest","");
      }
    else tell_object(ob,"这一桌人已经满了，你还是去别处看看吧。\n");
    }
  else return notify_fail("你已经在游戏中了！\n");
  return 1;
}

int valid_leave(object me, string dir)		//离开房间
  {
  if( query_member(me) )
    return notify_fail("你要先离开博饼桌才能离开这里。\n"); 
  return 1; 
}

int delete_member(object ob)
  {
  int i;
  if (!arrayp(member)) return 0;
  for (i=0;i<sizeof(member);i++) 
    {
    if (member[i]==ob) 
      {
      member-=({ob});
      ob->delete_temp("cocacola");
      break;
      }
    }
}

int add_member(object ob)
  {
  if (!arrayp(member)) 
    {
    member=({ob});
    leader=ob;
    }
  else 
    {
    member+=({ob});
    if (sizeof(member)>=minperson)  
      {
      allow_start=1;
      if (startbp==1)
        {
        tell_room(environment(leader),"好了，人够了，可以开始玩了。\n");
        tell_room(environment(leader),leader->query("name")+"先丢吧。\n");
        }
      }
    }
  return 1;
  }

int query_member(object ob)
  {
  int i;
  if (!arrayp(member)) return 0;
  return member_array(ob,member)+1; // mon
  
  for (i=0;i<sizeof(member);i++) 
    {
    if (member[i]==ob) 
      {
      return i+1;
      }
    }
  return 0;
}

int do_yao()
  {
  int s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore;
  
  object ob;
  string result1,result,dest;
  ob=this_player();
  getscore=0;
  dest="";
  s1=random(6)+1;
  s2=random(6)+1;
  s3=random(6)+1;
  s4=random(6)+1;
  s5=random(6)+1;
  s6=random(6)+1;
  //按点数统计
  c1=countit(s1,s2,s3,s4,s5,s6,1);//一的个数
  c2=countit(s1,s2,s3,s4,s5,s6,2);//二的个数
  c3=countit(s1,s2,s3,s4,s5,s6,3);//三的个数
  c4=countit(s1,s2,s3,s4,s5,s6,4);
  c5=countit(s1,s2,s3,s4,s5,s6,5);
  c6=countit(s1,s2,s3,s4,s5,s6,6);

if(c1==6||c2==6||c3==6||c4==6||c5==6||c6==6){
  getaward=6;	
  if(c1==6) {
	dest="六浮红(一)";
	getscore=1201;
  	}	
  if(c2==6) {
	dest="六浮黑(二)";
	getscore=1202;
	}

  if(c3==6){
	 dest="六浮黑(三)";
	getscore=1203;
	}
  if(c5==6) 
	{dest="六浮黑(五)";
	getscore=1204;
	}
  if(c6==6) 
	{dest="六浮黑(六)";
	getscore=1205;
	}
  if(c4==6) {
	dest="六浮红(通吃)";
	getscore=1206;
	}

}

else if(c4==5){
  getaward=6;	
  if(c1==1){
	dest="五红带一";
	getscore=1102;
  }
  if(c2==1){
	dest="五红带二";
	getscore=1103;
  }
  if(c3==1){
	dest="五红带三";
	getscore=1104;
  }
  if(c5==1){
	dest="五红带五";
	getscore=1105;
  }
  if(c6==1){
	dest="五红带六";
	getscore=1106;
  }

}


else if(c6==5){
  getaward=6;	
  if(c1==1){
	dest="五主(六)带一";
	getscore=1002;
  }
  if(c2==1){
	dest="五主(六)带二";
	getscore=1003;
  }
  if(c3==1){
	dest="五主(六)带三";
	getscore=1004;
  }
  if(c5==1){
	dest="五主(六)带五";
	getscore=1005;
  }
  if(c4==1){
	dest="五主(六)带四";
	getscore=1006;
  }

}


else if(c5==5){
  getaward=6;	
  if(c1==1){
	dest="五主(五)带一";
	getscore=902;
  }
  if(c2==1){
	dest="五主(五)带二";
	getscore=903;
  }
  if(c3==1){
	dest="五主(五)带三";
	getscore=904;
  }
  if(c6==1){
	dest="五主(五)带六";
	getscore=905;
  }
  if(c4==1){
	dest="五主(五)带四";
	getscore=906;
  }

}

else if(c3==5){
  getaward=6;	
  if(c1==1){
	dest="五主(三)带一";
	getscore=802;
  }
  if(c2==1){
	dest="五主(三)带二";
	getscore=803;
  }
  if(c5==1){
	dest="五主(三 )带五";
	getscore=804;
  }
  if(c6==1){
	dest="五主(三)带六";
	getscore=805;
  }
  if(c4==1){
	dest="五主(三)带四";
	getscore=806;
  }

}


else if(c2==5){
  getaward=6;	
  if(c1==1){
	dest="五主(二)带一";
	getscore=702;
  }
  if(c3==1){
	dest="五主(二)带三";
	getscore=703;
  }
  if(c5==1){
	dest="五主(二)带五";
	getscore=704;
  }

  if(c6==1){
	dest="五主(二)带六";
	getscore=705;
  }
  if(c4==1){
	dest="五主(二)带四";
	getscore=706;
  }

}

else if(c1==5){
  getaward=6;	
  if(c2==1){
	dest="五主(一)带二";
	getscore=602;
  }
  if(c3==1){
	dest="五主(一)带三";
	getscore=603;
  }
  if(c5==1){
	dest="五主(一)带五";
	getscore=604;
  }

  if(c6==1){
	dest="五主(一)带六";
	getscore=605;
  }
  if(c4==1){
	dest="五主(一)带四";
	getscore=606;
  }

}

else if (c4==4){
  getaward=6;	
  if((s1+s2+s3+s4+s5+s6-16)==2){
	dest="状元叉金花";
	getscore=1300;
	}
  if((s1+s2+s3+s4+s5+s6-16)==12){
	dest="状元带十二";
	getscore=512;
	}
  if((s1+s2+s3+s4+s5+s6-16)==11){
	dest="状元带十一";
	getscore=511;
	}
  if((s1+s2+s3+s4+s5+s6-16)==10){
	dest="状元带十";
	getscore=510;
	}
  if((s1+s2+s3+s4+s5+s6-16)==9){
	dest="状元带九";
	getscore=509;
	}
  if((s1+s2+s3+s4+s5+s6-16)==8){
	dest="状元带八";
	getscore=508;
	}
  if((s1+s2+s3+s4+s5+s6-16)==7){
	dest="状元带七";
	getscore=507;
	}
  if((s1+s2+s3+s4+s5+s6-16)==6){
	dest="状元带六";
	getscore=506;
	}
  if((s1+s2+s3+s4+s5+s6-16)==5){
	dest="状元带五";
	getscore=505;
	}
  if((s1+s2+s3+s4+s5+s6-16)==4){
	dest="状元带四";
	getscore=504;
	}
  if((s1+s2+s3+s4+s5+s6-16)==3){
	dest="状元带三";
	getscore=503;
	}

}


else if(c1==4||c2==4||c3==4||c5==4||c6==4){
  getaward=3;	
  if (c4==2){
	getscore=302;
	dest="四进带二举";
	}
  if(c4==1){
	getscore=301;
	dest="四进带一秀";
	}
  if(c4==0){
	getscore=300;
	dest="四进";
	}
}

else if(c4==3) {
	getaward=4;
	getscore=400;
	dest="三红";
	}
else if(c4==2) {
	getaward=2;
	getscore=200;
	dest="二举";
	}

else if (c4==1){
  if(c1==1&&c2==1&&c3==1&&c5==1&&c6==1) {
	getaward=5;
	getscore=500;
	dest="对堂";
	}
  else {
	getaward=1;
	getscore=100;
	dest="一秀";
	}
}
else {
	getaward=0;
	getscore=0;
	dest="．．．哎呀！什么都不是哦？！\n";
}
	
  result=" -------  -------  -------  -------  -------  -------\n"+
      "|       ||       ||       ||       ||       ||       |\n"+
      "|   "+checkcolor(s1)+"%d"+NOR+
      "   ||   "+checkcolor(s2)+"%d"+NOR+
      "   ||   "+checkcolor(s3)+"%d"+NOR+
      "   ||   "+checkcolor(s4)+"%d"+NOR+
      "   ||   "+checkcolor(s5)+"%d"+NOR+
      "   ||   "+checkcolor(s6)+"%d"+NOR+
      "   |\n"+  
      "|       ||       ||       ||       ||       ||       |\n"+  
      " -------  -------  -------  -------  -------  -------\n";  
  result=sprintf(result,s1,s2,s3,s4,s5,s6);
  result1="居然是个"+dest+"！";
  message_vision("$N抓起六个股子,放在手心里拼命摇，口中还念念有词道：\n"+
  "天灵灵，地灵灵．．．来来来，开了．．．\n",ob);

  is_busy=1;
  call_out("do_yao1",1+random(2),ob,result,result1,
	  getaward,getscore,dest);

  return 1;
  }
  
void do_yao1(object ob, string re,string re1, int getaward,
	int getscore, string dest)
{
    if(!ob) {
	is_busy=0;
	return;
    }
    message_vision(re,ob);
    call_out("do_yao2",2+random(3),ob,re1,getaward,getscore,dest);
}

void do_yao3() {is_busy=0;}
void do_yao2(object ob, string re1,int getaward,int getscore,string dest)
{
    int s1;
    if(!ob) {
	is_busy=0;
	return;
    }
    message_vision(re1,ob);
    s1=getit(ob,getaward,getscore,dest);
    if(!s1) {
	pass_token(query_member(ob),0);
    }
    call_out("do_yao3",1+random(2));
}

string checkcolor(int i)		//股子的一和四都是红色的
  {
  if(i==4) return HIR;
  else if(i==1) return HIR;
  else return "";
  }

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
  {  //计算点数
  int i;
  i=0;
  if (s1==sd) i++;
  if (s2==sd) i++;
  if (s3==sd) i++;
  if (s4==sd) i++;
  if (s5==sd) i++;
  if (s6==sd) i++;
  return i;
}

int getit(object ob,int getaward,int getscore,string dest)
  {
  object* play,nil;
  int nowat;


/*  if (getaward>(ob->query_temp("cocacola/maxaward"))) 
    {
    ob->set_temp("cocacola/maxaward",getaward ); 
    ob->set_temp("cocacola/dest",dest);
    }
  if (getscore>(ob->query_temp("cocacola/maxscore"))) 
     ob->set_temp("cocacola/maxscore",getscore); 
*/
  if (getaward==1) 
    {
    if (Max1<=0 )
      {
      tell_room(environment(ob),CYN"可惜啊！一秀已全被博光了，继续努力吧．．．\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g1",ob->query_temp("cocacola/g1")+1); 
      if(Realmode) 
        {
//        ob->add("combat_exp",100);
	ob->add("potential",1);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 1 pot.\n");
        message_vision(HIY"$N博到一秀一个，奖潜能1点！\n"NOR,ob);
        Max1--;
        }
      else 	
        message_vision(CYN"$N博到一秀一个，但巫师还没把宝囊打开，不能得奖品.\n"NOR,ob); 
      }
    }
  if (getaward==2) 
    {
    if (Max2<=0 )
      {
      tell_room(environment(ob),CYN"可惜啊！二举已全被博光了，继续努力吧．．．\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g2",ob->query_temp("cocacola/g2")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",200);
	ob->add("potential",2);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 2 pot.\n");
	message_vision(HIY"$N博到二举一个，奖潜能2点！\n"NOR,ob);
	Max2--;
	}
      else 	
        message_vision(CYN"$N博到二举一个，但巫师还没把宝囊打开，不能得奖品.\n"NOR,ob); 
      }
    }
  if (getaward==3) 
    {
    if (Max3<=0 )
      {
      tell_room(environment(ob),CYN"可惜啊！四进已全被博光了，继续努力吧．．．\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g3",ob->query_temp("cocacola/g3")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",500);
	ob->add("potential",3);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 3 pot.\n");
	message_vision(HIY"$N博到四进一个，奖潜能3点！\n"NOR,ob);
	Max3--;
	}
      else 	
	message_vision(CYN"$N博到四进一个，但巫师还没把宝囊打开，不能得奖品.\n"NOR,ob); 
	give_cake(ob);
      }
    }
  if (getaward==4) 
    {
    if (Max4<=0 )
      {
      tell_room(environment(ob),CYN"可惜啊！三红已全被博光了，继续努力吧．．．\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g4",ob->query_temp("cocacola/g4")+1); 
      if(Realmode) 
        {
//	ob->add("combat_exp",1000);
	ob->add("potential",4);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 4 pot.\n");
	message_vision(HIY"$N博到三红一个，奖潜能4点！\n"NOR,ob);
	Max4--;
	}
      else 	
        message_vision(CYN"$N博到三红一个，但巫师还没把宝囊打开,不能得奖品.\n"NOR,ob); 
      }
    }
  if (getaward==5) 
    {
    if (Max5<=0 ) 
      {
      tell_room(environment(ob),CYN"可惜啊！对堂已全被博光了，继续努力吧．．．\n"NOR);
      }
    else 
      {
      ob->set_temp("cocacola/g5",ob->query_temp("cocacola/g5")+1); 
      if(Realmode) 
        {
 //       ob->add("combat_exp",1000);
        ob->add("potential",8);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 8 pot.\n");
        message_vision(
		HIY"$N博到对堂一个，奖潜能8点！\n"NOR,ob);
        Max5--;
        }
      else 	 
        message_vision(CYN"$N博到对堂一个，但巫师还没把宝囊打开，不能得奖品.\n"NOR,ob); 
	give_cake(ob);
      }
    }
  if (getaward==6) 
    {
    Max6=0;
    if ((getscore==1202)||(getscore==1203)||(getscore==1205)||(getscore==1206))
      {
      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	      "============\n不幸，不幸！"+ob->query("name")+"博到了"+dest+"！！从此退出博饼圈！！！\n"NOR);
      Maxperson++;
      delete_member(ob);
      if(ob==winner) winner=0;
      return 0;	      
      }
    if ((getscore==1201)||(getscore==1204))
      {
      winner=ob;
            
      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
     	      "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"！！通杀,太可怕了！！！\n"NOR); 
      
      game_over(0);	
      return 1;	 
      }
     

      if (ob->query_temp("cocacola/g6")==0)
        ob->set_temp("cocacola/g6",ob->query_temp("cocacola/g6")+1);
      ob->set_temp("cocacola/score",getscore);

    if (jinhua==1)
      {
      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
     	      "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"！！\n"+
	      "不过已经有人博到状元插金花,现在争状元已经没有意义了！！！\n"NOR); 
      return 0;
      }

    if (getscore==1300)
      {
      winner=ob;
      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	      "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"太幸运了,现在可是绝对的状元了！！"NOR);
      jinhua=1;
      Max5=0;
/*    ob->add("combat_exp",2000);
*/  
      if(Realmode) {
      ob->add("potential",10);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 10 pot.\n");
      message_vision(HIY"$N博到状元一个，奖潜能10点！\n"NOR,ob);
      }
	give_cake(ob);
     //** 请加入奖励
      return 0;		        
      }

      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	      "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"！！"NOR);



      if(!winner)
        {
        winner=ob;
        play=users();
        tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	        "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"！！成为"+roomname+"的新状元！！！\n"NOR);
        }
      else
        {
        nowat=getnewzy();
        if (ob==winner)
          {
          play=users();
          tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	        "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"！！成为"+roomname+"的新状元！！！\n"NOR);
          }
        else
          {
          play=users();
          tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	        "============\n目前的状元是！"+winner->query("name")+"！！！\n"NOR);
          } 
        }	
   



    if(Realmode) 
      {
//      ob->add("combat_exp",2000);
      ob->add("potential",10);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 10 pot.\n");
//      message_vision(HIY"$N博到状元一个,奖经验点2000点,潜能50点,涨悟性，根骨，灵性各一点.\n"NOR,ob);
      message_vision(HIY"$N博到状元一个，奖潜能10点！\n"NOR,ob);
      }
    else 	
      message_vision(CYN"$N博到状元一个，但巫师还没把宝囊打开，不能得奖品.\n"NOR,ob); 
	give_cake(ob);

    }

/*
  if(getaward>=6)
    {
    if(!objectp(winner))
      {
      winner=ob;
      play=users();
      tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	      "============\n恭喜，恭喜！"+ob->query("name")+"博到了"+dest+"!!成为"+roomname+"的新状元!!!\n"NOR);
      }
    else 
      {	
      if(ob!=winner&&getscore>winner->query_temp("cocacola/maxscore"))
        {
        winner=ob;
        play=users();
        tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
	      "============\n恭喜，恭喜!"+ob->query("name")+"博到了"+dest+"!!成为"+roomname+"的新状元!!!\n"NOR);
        }
      }
    }
*/

  if (Max1+Max2+Max3+Max4+Max5+Max6==0)
    {
    game_over(0);    
    return 0;
    }
  return 0;

  }

void game_over(int i)
  {
  object *play,ob;
  ob=winner;
  play=users();
  tell_room(here,HIY"\n\n[博饼最新消息]\n=================================="+
       "============\n"+roomname+"的博饼结束了！！！\n"NOR);
  if(!i) {
      if(winner) {
        tell_room(here,HIY"恭喜，恭喜！"+ob->query("name")+"荣升状元！\n"NOR);
	if(Realmode) {
	winner->add("combat_exp",200);
      log_file("bobing",ctime(time())+" "+ob->query("id")+" got 200 dx.\n");
	tell_room(here,HIY+ob->query("name")+"得到了五十天道行！\n"NOR);
	}
	give_cake(ob);
      }
//  if (jinhua!=1)
//    {
  //** 请在这里加入对状元的奖励.
 //   }
  //如果没有在以上对状元插金花做奖励请在可以做奖励
  }

  startbp=0;stopbp=0;
  Max1=32;Max2=16;Max3=8;Max4=4;Max5=2;Max6=1;
  NowLea=-1;jinhua=0;
  member=0;
  Realmode=0;
        Maxperson=12;
	minperson=4;
	allow_leave=1;
	allow_start=0;
  startbp=0;
  winner=0;
  }

int getnewzy()
  {
  int i,nowat,maxscore;
  if (!arrayp(member)) return 0;
  maxscore=member[0]->query_temp("cocacola/score");    
  nowat=0;
  for (i=0;i<sizeof(member);i++) 
    {
    if (maxscore<member[i]->query_temp("cocacola/score"))
      {
      maxscore=member[i]->query_temp("cocacola/score");    
      nowat=i;  
      winner=member[i];
      }    
    }
  return nowat+1; 
  }
