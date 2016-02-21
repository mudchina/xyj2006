//  妖神之争  １。０
//  by happ@YSZZ 2000.04.09
//  .... 

inherit ROOM;

void create ()
{
  set ("short", "谷底");
  set ("long", @LONG

正上方就是飞凤峰，你也不清楚自己是怎么会到这个地方的。旁边
的地上好象埋藏着些什么东西。

LONG);
  set("outdoors", 1);
  setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_dig","dig");
}

int do_climb(string arg)
{
        object ob = this_player();
 
                 if( ! arg || arg != "cliff" )
                        return notify_fail("你要爬什么。\n");

                if ( random(4) == 2 )
                   {
                     message_vision("只见$N一头栽了下来。\n",ob);
                     ob->unconcious();
                    return 1;
                    }
            message_vision("只见$N小心的向上爬去。\n",ob);
            ob->move("/d/meishan/cuiping");
            return 1;
}

int do_dig(string arg)
{
        object ob = this_player();
        object wield;
        object zhu=new("/d/obj/baowu/tuzhu");
//if (zhu->query_unique()) zhu =new("/d/sea/obj/pearl");
if (zhu->query_unique()) zhu =new("/d/obj/baowu/tuzhu");
                
        if ( ! arg || arg != "di" )
                return notify_fail("你要挖什么？\n");

        if( ob->query_temp("tz_find") )
                return notify_fail("你怎么这么贪心。\n");

        if(!wield=ob->query_temp("weapon"))
                return notify_fail("你身上没有利器。\n");

        if(((string)wield->query("skill_type")!="sword"
             && ((string)wield->query("skill_type")!="blade")))
                return notify_fail("你应该找把剑，或是刀什么的。\n");

        if( random(6) == 3 )
            {
         ob->add("kee",-50);
         message_vision("$N用力挖了一会，突然感觉有个东西埋在地下。\n",ob);
         message_vision("$N居然发现一个土灵珠。\n",ob);
         zhu->move(ob);
         ob->set_temp("tz_find",1);
         return 1;
             }
        ob->add("kee",-50);
        message_vision("$N费了大办天的劲，什么也没有挖到。\n",ob);
        return 1;
}
