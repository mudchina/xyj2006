//Cracked by Roath


inherit NPC;

string *banned_name = ({
	"你", "我", "他", "她", "它", "它", "江泽民", "邓小平", "李鹏", "朱榕基",
	"自己", "某人", "尸体", "我们","你们", "他们", "大家",
	"他妈的", "去你的", "毛泽东", "巫师", "他奶奶的",
});

int check_legal_name(string name);

void create()
{
        set_name("长孙无忌", ({"zhangsun wuji","minister","wuji","zhangsun"}));
        set("gender", "男性");
        set("title","户部尚书");
        set("age", 50);
        set("attitude", "friendly");
        set("combat_exp", 250000);
        set("per", 30);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();

}

void init()
{
   ::init();
   add_action("do_newname", "newname");
   add_action("do_apply", "apply");
   add_action("do_confirm","confirm");
   this_player()->delete_temp("new_rank");

}
       
int do_apply(string arg)
{
  string type,rank;   
  object me=this_player();
  string msg="你准备将";
  int afford;

   if (!arg) return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格／道行要求：
self        对自己的称呼      五十两黄金   一百年
self_rude   对自己的粗鲁称呼  五十两黄金   一百年
respect     别人对自己的尊称  五十两黄金   五百年

又：请勿使用不恰当的称谓。不然称呼被取消，五十两
金子就白白扔了。至于恰当与否，则由天上神仙决定。

LONG);
  if (sscanf(arg,"%s to %s",type,rank)!=2)   return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格：
self          对自己的称呼         五十两黄金
self_rude     对自己的粗鲁称呼     五十两黄金
respect       别人对自己的尊称     五十两黄金

又：请勿使用不恰当的称谓。不然称呼被取消，五十两
金子就白白扔了。至于恰当与否，则由天上神仙决定。

LONG);
  
  if (type!="self" && type!="respect" && type!="self_rude")
    return notify_fail("不能设置这种类型的称呼。\n");

  if (type!="respect" && me->query("daoxing")<100000) 
    return notify_fail("你道行那么低，本来就没人听说过你，不改也罢。\n");
  if ( type=="respect" && me->query("daoxing")<500000)
    return notify_fail("你本领还不够，别人不会听你这样叫的。\n");

  if( !(afford=me->can_afford(500000)) )  {
     write("你带的钱不够。\n");
     return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

  switch (type) {
    case "self" : msg+="对自己的称呼从现在的“"+RANK_D->query_self(me);break;
    case "self_rude" : msg+="对自己的粗鲁称呼从现在的“"+RANK_D->query_self_rude(me);break;
    case "respect" :  msg+="别人对自己的尊称从现在的“"+RANK_D->query_respect(me);break;
  }
  msg+="”改成“"+rank+"”，是这样吗？(confirm)\n";
  write(msg);
  me->set_temp("new_rank/type",type);
  me->set_temp("new_rank/ready",1);
  me->set_temp("new_rank/rank",rank);
  return 1;
}

int do_confirm() {
  object me=this_player();
  int afford;

  if (!me->query_temp("new_rank/ready"))
     return notify_fail("你要确认什么？\n");

  if( !(afford=me->can_afford(500000)) )  {
       write("你带的钱不够。\n");
       return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

  message_vision("$N拿出五十两金子，交给了$n。\n",me,this_object());
  message_vision("$N点了点头，拿出一份卷宗写了几笔。\n",this_object());
  me->pay_money(500000);
  if (me->query_temp("new_rank/rank")=="cancel")
     me->delete("rank_info/"+me->query_temp("new_rank/type"));
  else 
     me->set("rank_info/"+me->query_temp("new_rank/type"),me->query_temp("new_rank/rank"));
  write("改动完毕。\n");
 log_file("change_rank",me->query("id")+" changes "+me->query_temp("new_rank/type")+" to "
      +me->query_temp("new_rank/rank")+" on "+ctime(time())+".\n");
 
 me->delete_temp("new_rank");
  return 1;
}


int do_newname(string arg)
{
   object me=this_player();
  int afford;

  if (!arg) return notify_fail(@LONG
格式： newname <新名字> 
价格： 二百两黄金(随身携带)

LONG);


     arg = CONVERT_D->input(arg,me);

	if( !check_legal_name(arg) ) {

		write("你输入的名字不合法!请重新输入!\n");
		return 1;
	    } else
{
  if( !(afford=me->can_afford(2000000)) )  {
     write("你带的钱不够。\n");
	return 1;
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
 }

  message_vision("$N拿出二百两金子，交给了$n。\n",me,this_object());
  message_vision("$N点了点头，拿出一份卷宗写了几笔。\n",this_object());
  me->pay_money(2000000);
  me->set("name",arg);
    write("你的名字更改完毕。\n");
	return 1;
}
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("对不起，你的中文名字必须是一到六个中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，你的中文名字不能用控制字符。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	return 1;

}
