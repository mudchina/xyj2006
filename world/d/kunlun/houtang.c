inherit ROOM;

void create()
{
        set("short", "后堂");
        set("long", @LONG
这是一间石室，里面只有一位老道长。四周全是石壁，
    只有道长身后有一根很细的绳索(rope)通向另外一边，
    你可以试试(climb) 。

LONG );
       set("exits", ([
               "south" : __DIR__"mishi",
       ]));

            set("objects",([
                __DIR__"npc/guang" : 1,
        ]));
        
       set("no_clean_up", 0);
       setup();
}
int valid_leave(object me,string dir)
{
        if(dir=="down" && (!me->query("family") || (me->query("family/family_name")!="昆仑山玉虚洞")) && present("niang",environment(me))) 
             return notify_fail("广成子伸手挡住了你的去路，说道：那里是我师傅修道的地方，外人不得入内！\n");
        return ::valid_leave(me,dir);
}
void init()
{
        add_action("do_climb", "climb");
}


int do_climb(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "rope") ))
                return notify_fail("你要往哪去？\n");
        else if(me->query("kee")<50)   
          {
           me->unconcious();
           message_vision("$N伸手拉住绳索，慢慢爬了过去。\n",me);
          }
        else
          {
           me->add("kee",-50); 
           message_vision("$N轻轻一跳，只见四周一片迷茫。\n",me);
           me->move("/d/kunlun/hundun");
           tell_room(environment(me),"只见"+me->name()+"从密室的那边爬了上来。\n", me);
           return 1;
           }
        return 1;
}
