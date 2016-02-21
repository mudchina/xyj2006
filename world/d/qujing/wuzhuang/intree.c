//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/intree.c


inherit ROOM;
#include <ansi.h>
void kill(object ob);
void appear(object ob);

void create ()
{
   set ("short", "果树上");
   set ("long", @LONG

你终于爬到了果树的顶上，人参果在你的身边摇摆不定，这人参果
三千年一开花，三千年一结果，再三千年才得熟，短头一万年才可
吃，那果子的模样，就和三朝未满的小孩相似，四肢齐全，五官俱
全。

LONG);

   set("exits", 
   ([ //sizeof() == 4
        "down": __DIR__"shugan3",
   ]));
   setup();
}
void init()
{
        add_action("do_hit","hit");
}

int do_hit()
{
        object ob = this_player();
        object wield,guo,guo1,guo2,guo3;
        object where = this_object();
       
       if( ob->is_busy() )
	        {
              message_vision("你现在正忙着呢。\n"NOR,ob);
			  return 1;
			}
        if( where->query("killed")||
            ob->query("kill_tree") )
            {
              message_vision("这棵树已经枯萎了。\n"NOR,ob);
			  return 1;
			}
                
        if(!wield=ob->query_temp("weapon"))
            {
              message_vision("你应该找个东西来打人参果。\n"NOR,ob);
			  return 1;
			}
        
		if (ob->query_temp("get_guo")>=6)
           {
              message_vision("别太贪心了。\n"NOR,ob);
			  return 1;
		   }

		if( (ob->query_temp("get_guo"))&&(ob->query("fangcun/panlong_wzg_baxian")=="done") )
           {
			if(( wield->query("id") != "jinji zi")||( ! ob->query_temp("prepared") ))
			   {
				message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着人参果敲去，\n",ob);
                message_vision(HIC"人参果只是咕碌一声，钻到地下不见了。\n",ob);
                return 1;
               }
			message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着树上的果子砸去。\n"NOR,ob);
            message_vision(HIC"一个人参果飘然的落在$N的盘子里面。\n"NOR,ob);
            guo3=new("/d/obj/drug/renshen-take");
            guo3->move(ob);
            ob->start_busy(random(10)+5);
            ob->add_temp("get_guo",1);
            return 1;
		   }
        
		if( wield->query("id") != "jinji zi"|| 
           ob->query("obstacle/wzg") == "done" )
           {
           message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着人参果敲去，\n",ob);
           message_vision(HIC"人参果只是咕碌一声，钻到地下不见了。\n",ob);
           return 1;
            }
        
         else  
                if( ! ob->query_temp("prepared") )
                   {
           message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着人参果敲去，\n",ob);
           message_vision(HIC"人参果只是咕碌一声，钻到地下不见了。\n",ob);
           return 1;
                  }
if ( ob->query("obstacle/wzg") == "done")
                  {
                message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着树上的人参果敲去。\n",ob);
                message_vision(HIC"一个人参果飘然的落在$N的盘子里面。\n"NOR,ob);
             guo2=new("/d/obj/drug/renshenguo-fake");
                guo2->move(ob);
                return 1;
                  }
                
  message_vision(HIC"只见$N举起手中"+wield->query("name")+"，对着树上的果子砸去。\n"NOR,ob);
  message_vision(HIC"一个人参果飘然的落在$N的盘子里面。\n"NOR,ob);
  remove_call_out("kill");
  remove_call_out("appear");
  call_out("kill",5,ob);
  call_out("appear",2,ob);
           guo=new("/d/obj/drug/renshenguo-fake");
  guo->move(ob);
  ob->start_busy(10);
  return 1;  
}
void appear(object ob)
{
        object where=this_object();

        object a = new("/d/qujing/wuzhuang/npc/mingyue");
        object b = new("/d/qujing/wuzhuang/npc/qingfeng");

        a->move(where);
        b->move(where);

        message_vision(HIW"\n忽然清风、明月闯了进来。\n",ob);
        message_vision(HIG"清风破口大骂：$N,这个混蛋，偷我们五庄观的人参果。\n",ob);
        message_vision(HIG"明月破口大骂：$N,你比猪还馋吗？\n",ob);
        message_vision(HIG"清风破口大骂：$N,你这个贼子，一家人都是贼，才生出这样的贼人。\n",ob);
        message_vision(HIG"明月破口大骂：$N,快把人参果从肚子里给我吐出来。\n",ob);
        message_vision(HIG"清风破口大骂：$N,你是不是平时也是偷鸡摸狗的货色。\n",ob);
        message_vision(HIG"明月破口大骂：$N,我看你是一身的贼骨头。\n",ob);
        message_vision(HIG"清风破口大骂：$N,你一定不得好死。\n",ob);
        message_vision(HIG"明月破口大骂：$N,他妈的，别怪老子不客气了。\n",ob);

  where->set("killer",ob->query("id"));
}
void kill(object ob)
{
        object wield=ob->query_temp("weapon");
        object where = this_object();
        object a = find_living("qing feng");
        object b = find_living("ming yue");

        message_vision(HIC"只见$N气的满脸通红，真是个怒发冲冠。\n",ob);
        message_vision(HIC"$N抡起手中的"+wield->query("name")+"对着人参果树狠命的砸了下去。\n"NOR,ob);
        message_vision(HIC"可怜一棵前年古树就这样慢慢的枯萎了。\n"NOR,ob);
        message("channel:chat",HIC"【闲聊】明月(Ming yue)：不好了！"+ob->query("name")+"把人参果树砸倒了。\n"NOR,users());
        tell_object(ob,"明月，清风飞也似的逃走了。\n");
        destruct(a);
        destruct(b);
        where->set("killed",1);
        ob->set_temp("kill_tree",1);
        return ;
}
