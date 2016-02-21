// obstacled.c
// by blacksh 01/06/99

// 取经精灵负责定期产生取经人,取经的全局变量

#pragma optimize

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;



void create()
{
    object env,qujingren;
    object me=this_object();

    seteuid(getuid());
    set("name", "取经精灵");
    set("id", "obstacled");
    if (!restore())		//第一次或者重新初始化过
      {

      }
    else
      {
        if (me->query("haved_qujingren")==1)
 	  {
            env=load_object(me->query("where_qujingren"));
                       //取经人最后一次出现的地方
            if (env && env->query("short")!="蒸笼房")
              {
  	        qujingren=find_living("qujing ren");
                if (!qujingren)
	          {
		    qujingren=new("/d/qujing/qujingren/"+me->query("guan")
                                +"/qujingren");
	          }
    	        qujingren->move(env);
  	      }
	  }	
     }

  if (me->query("haved_qujingren")==1)
    {
      return ;	//已经产生取经人 
    }  

  remove_call_out("choose_qjr");
  call_out("choose_qjr",3600*24*5);   //五天产生一个取经人
	

}


void choose_qjr()
{	//开始选择取经人

  	object   env,tang,me;

	me=this_object();
	env=load_object("/d/huanggong/dadian");
	tang=present("xu",env);
	tang->command_function("chat 奉天承运,皇帝诏曰：兹寻护送前往西天取经
高僧之卫士，望天下勇士前来参选，选中必有重赏．钦此");	
	me->set("choose_qjr",1);
	me->add("this_qj_time");
	me->set("number",0);
	me->set("min_time",0);
	remove_call_out("over_choose_qjr");
        call_out("over_choose_qjr",3600*24);    //给一天让玩家参选
						
}


void over_choose_qjr()
{	//选取经人结束
	
  	object  env,tang,me;
	int 	number,choose_number;
	mixed 	qujing_times;
	string 	*keys,min,id,name;
	int 	size,i,inc=0;
	mixed   inchoose,temp;


	me=this_object();
	env=load_object("/d/huanggong/dadian");
	tang=present("tang",env);
        me->delete("choose_qjr");
	number=me->query("number");

	if (number<1)
	  {
	    tang->command_function("chat  想我堂堂大唐，竟然无一英雄！");
  	    remove_call_out("choose_qjr");
	    call_out("choose_qjr",3600*24*5);	//五天产生一个取经人
	    return;
	  }

	if (number==1)
	  {
	    id=me->query_temp("chooseman/1/id");
	    name=me->query_temp("chooseman/1/name");
	    tang->command_function("chat* 封"+name+"("+id+")为护国法师,"
		+"护送取经人前往西天取经！");
	    me->set("husong",id);	
            me->delete("obstacl_fail");
	    return;
	  }


	
	qujing_times=me->query("qujing_times");	//在第三关中有设定相关的参数
	keys=keys(qujing_times);
	size=sizeof(qujing_times);
        inchoose = allocate (size);
	
		
	min=keys[0];
	for (i=1;i<size;i++)
	  {
	    if ( min<keys[i] )	//选出最少失败次数的玩家系列
	      {
		temp=me->query("qujing_times/"+keys[i]);
 	      }
	    else
	      {
		temp=me->query("qujing_times/"+min);
		min=keys[i];
	      }
  	    inchoose[inc]=temp[random(sizeof(temp))];	
		//从这个系列中选出一个玩家．放到inchoose
	    inc++;
	  }

	i=inchoose[random(inc)];	
	me->set("qujing_times/"+min+"/"+i,i);
		//选出一个玩家加入到最后的选择
	size=sizeof(me->query("qujing_times/"+min));
	i=me->query("qujing_times/"+min+"/"+random(size));
	
	//本段的作用是:
	//根据玩家取经失败的次数来随机选取取经人．
	//首先排除了最少取经次数的玩家．
	//然后依照各自的次数随机选出该序列的玩家．
	//将选出的结果放到inchoose中，从这个结果中选出一个玩家
	//而后将这个玩家放到放到最少次数的系列．
	//最后从这个系列中选出一个玩家，这个玩家就是最后选定的取经人．

	//这段的设计主要是为了给较少失败的人更多的机会．


/*	
	if (number>1)
	  {
	    choose_number=random(number+1);
	    if (choose_number==0)
	      {
		choose_number=me->query("min_man"); //给时间最短的人多个机会
	      }

	  }
*/

         id=me->query_temp("chooseman/"+i+"/id");
	 name=me->query_temp("chooseman/"+i+"/name");
	 tang->command_function("chat* 封"+name+"("+id+")为护国法师,"
		+"护送取经人前往西天取经！");
	 me->set("husong",id);	
	 return;


}



int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "qujing/obstacled"; }


void back_fabao()
{	//蒸笼老人要求一个小时内返回法宝
 
  remove_call_out("backme");
  call_out("backme",3600);

}

void back()
{
   object fabao,env;

   fabao=find_object("tianmo jian");				
   if (fabao)
     {
	env=environment(fabao);
	if (interactive(env))env=environment(env);  
	message("sound","空中一声大吼,无用的家伙,还我天魔茧来\n",env);
   	destruct(fabao);
     }
   this_object()->delete("last_jie_id")	;

}

void punish_player(object who)
{	//如果取经人别吃,取经失败,在这里对玩家做惩罚
	//由于如果取经人被吃后,护送玩家不一定在线,因此需要在
	//logind中修改如果护送玩家连线就做punish_player();

     who->delete("obstacle/qujing");

}


void qujing_fail()
{
  remove_call_out("do_qujing_fail");
  call_out("do_qujing_fail",3600);
}

void do_qujing_fail()
{	//取经人被抓24小时如果没有被救出来就算取经失败.(被蒸熟了:D)
  
   object me,who;
   me=this_object();
   who=this_player();


   me->set("obstacle_fail",1);
   me->save();

   if (who=find_player(OBSTACLE_D->query("husong")))
      {
	punish_player(who);
      }
   
}

 


void open_door()
{
  remove_call_out("do_open_door");
  call_out("do_open_door",120);
}

void do_open_door()
{
  this_object()->set("open_door",1);
}
