void init()
{
    object where=this_object();

        remove_call_out("delete");
        call_out("delete",3,where);
    add_action("do_feel","tang");
}

int do_feel(string arg)
{
        object me = this_player();
        string place;
        object yao;

        if ( me->is_busy() )
                return notify_fail("你正忙着呢！\n");

        if( ! arg || arg != "stone" )
                return notify_fail("你要淌什么?\n");
        if( me->query("obstacle/yj") == "done" )
                return notify_fail("你什么也没有淌到。\n");

        if( me->query_temp("find") )
                return notify_fail("你已经发现某个地方有入口了，还不快去找？\n");       

        if( random(5) < 2 )
        {
        place = "/d/qujing/yingjian/jiandi1";
        place[strlen(place)-1] = '0'+random(10);
        message_vision("$N仔细淌了淌脚下的石头,发现周围的珊瑚好象动了一下！\n",me);
        place->set("exits/down", __DIR__"shanhu");
        me->start_busy(1);     
        me->set_temp("find",1);
        return 1;
        }

        tell_object(me,"糟了，你惊醒了水怪！\n");
        yao=new(__DIR__"npc/yao");
        yao->move(environment(me));
        yao->set_leader(me);
        return 1;
        }

void delete(object where)
{
        if(query("exits/down"))
        this_object()->delete("exits/down");
        else return;
}
