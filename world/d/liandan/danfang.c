//炼丹室
//canoe 
#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_liandan();
int do_stop();

void create()
{
    set("short", "炼丹室");
    set("long", @LONG

这里除了个大丹炉外什么也没有，整个房间里弥漫着一种丹药味。

LONG );

set("exits", ([
         "up" : __DIR__"datang",
    ]));
    
set("objects", ([
                __DIR__"obj/daotong": 1,
                __DIR__"obj/danlu": 1,
                 ]) );
  set("no_magic", 1);
  set("no_fight", 1);
   
     setup();
}

int init()
{
        add_action("do_liandan","liandan"); 
        add_action("do_stop","stop");
        add_action("do_get","get");
}

int do_liandan()
{       int kar;
        string str;
        object me = this_player();
        
        // 变量说明:yxld==允许炼丹
        //          nlcs==能炼次数
        //          ldcs==能炼次数
        //          ldwp==炼丹物品参数,目前分2000 4000
        
        if(!me->query_temp("yxld"))
                    return notify_fail("你原料都没给道童，怎么炼？\n");
        if(me->is_busy()) 
                   return notify_fail("你现在正忙着呢！\n");
        if(me->query("kee")<200||me->query("sen")<200)
                   return notify_fail("你还是先休息一下吧，炼丹很耗气血和精神的哦。\n");
                
         kar = me->query("kar")*2;
        if (!me->query_temp("nlcs")) me->set_temp("nlcs",random(kar)/5);
                
        me->start_busy(3+random(10));
        message_vision(MAG"$N鼓动真气，把自己毕生的道行化做一团真火喷向丹炉。\n"NOR, me);
       
        me->receive_damage("kee",random(100));
        me->receive_damage("sen",random(100));
       
        if (random(kar)>3)
            {
            if( me->query_temp("ldcs")>=me->query_temp("nlcs"))
                {
		
		kar=random(7);// 节省变量, 不提倡这样 :P
me->set_temp("ldcs",(int)me->query_temp("ldcs")/2);
		if(kar==0)
		    {
			message_vision(HIR"炉里的火猛的一跳，$N终于炼好了一个香气四溢的潜能丹。\n"NOR,me);
 	                message_vision(CYN"$N喜出望外,一口吞下这颗潜能丹。\n"NOR,me);
kar=(int)me->query_temp("ldwp")/4+random(500)+(int)me->query_temp("ldcs")*40+(int)me->query_temp("nlcs")*20;
 	                tell_object(me,"你获得了"+kar+"的潜能！\n");
        	        str=me->query("name")+"成功地炼出了颗潜能丹,获得了"+kar+"的潜能奖励！";
                	CHANNEL_D->do_channel(me,"rumor",str);
        	        kar=(int)me->query_temp("ldwp")+random(2000);
                	me->add("potential",kar);
                    }
    		else if(kar==1)
    		    {
    		        message_vision(HIR"炉里的火猛的一跳，$N终于炼好了一个香气四溢的武学丹。\n"NOR,me);
 	                message_vision(CYN"$N喜出望外,一口吞下这颗武学丹。\n"NOR,me);
kar=(int)me->query_temp("ldwp")+random(1000)+(int)me->query_temp("ldcs")*200+(int)me->query_temp("nlcs")*100;
        	        tell_object(me,"你获得了"+kar+"的武学经验！\n");
        	        str=me->query("name")+"成功地炼出了颗武学丹,获得了"+kar+"的武学奖励！";
                	CHANNEL_D->do_channel(me,"rumor",str);
                	me->add("combat_exp",kar);
                   }
                else if(kar==2) 
                   {    
                        message_vision(HIR"炉里的火猛的一跳，$N终于炼好了一个香气四溢的道行丹。\n"NOR,me);
 	                message_vision(CYN"$N喜出望外,一口吞下这颗道行丹。\n"NOR,me);
kar=(int)me->query_temp("ldwp")+random(500)+(int)me->query_temp("ldcs")*400+(int)me->query_temp("nlcs")*400;
        	        tell_object(me,"你获得了"+COMBAT_D->chinese_daoxing(kar)+"的道行！\n");
        	        str=me->query("name")+"成功地炼出了颗道行丹,获得了"+COMBAT_D->chinese_daoxing(kar)+"的道行奖励！";
                	CHANNEL_D->do_channel(me,"rumor",str);
                	me->add("daoxing",kar);
                   
                   }   
    		else 
    		   {   
                        message_vision(HIR"炉里的火猛的一跳，炼出来的竟然是黄金!\n"NOR,me);
 	                message_vision(CYN"$N喜出望外,赶紧把这些钱存在银行里。\n"NOR,me);
kar=(int)me->query_temp("ldwp")*20+random(50000)+(int)me->query_temp("ldcs")*8000+(int)me->query_temp("nlcs")*4000;
        	        tell_object(me,"你获得了"+chinese_number(kar/10000)+"两黄金！\n");
        	        str=me->query("name")+"误打误撞,竟然炼出了"+chinese_number(kar/10000)+"两黄金！";
                	CHANNEL_D->do_channel(me,"rumor",str);
                	me->add("balance",kar);
                   }
    	        me->delete_temp("yxld");
		me->delete_temp("ldcs");
		me->delete_temp("nlcs");
		me->delete_temp("ldwp");
                      log_file("liandan",sprintf("%s(%s)(%s)\n",
				geteuid(me),str,ctime(time()) ) );
    	        return 1;
    	       }
    	    else {
    	        message_vision(HIR"只见炉里的火更旺了。。。\n"NOR,me);
    	        me->add_temp("ldcs",1);
    	        return 1;
    	         }
    	  }
        else 
           	{
                me->receive_wound("kee", random(100));  
                me->receive_wound("sen",random(50));
                message_vision(RED"$N行功时突然走火入魔，口喷鲜血栽倒在地。\n"NOR,me );
                me->add_temp("ldcs",1);
     		me->unconcious();
     		 return 1;
     		}
}

int do_stop()
{
object me=this_player();
if (!me->query_temp("yxld")) return notify_fail ("你并没有在炼丹，无需中止。\n");
me->delete_temp("yxld");
me->delete_temp("ldcs");
me->delete_temp("ldwp");
me->delete_temp("nlcs");
message_vision("$N思前想后,中止了炼丹。\n",me );
return 1;
}

int valid_leave(object me, string dir)
{       
        
        if (dir == "up" && me->query_temp("yxld") ) {
               
                return notify_fail("小道童对你说到：炼完丹再走吧！\n");
        return ::valid_leave(me, dir);
        }
        return 1;
}

int do_get(string arg)
{
        string from;
        object me = this_player();
        object env;
        
        if( !arg ) return 0;
                
        if( sscanf(arg, "%s from %s", arg, from)==2 )
            {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"小道童对你摇了摇头。\n");
                         return 1;
                      }
            }
        
        else {
                env = present(arg, environment(me));
 if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"小道童对你摇了摇头。\n");
                         return 1;
                      }
             }
                        
        return 0;
}               
