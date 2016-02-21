// writted by mind

inherit ROOM;
void create()
{
        set("short", "火窟");
        set("long", @LONG
火焰山附近的一个山洞，里面都是赤红的岩石。地上小沟流的居然是
殷红的岩浆。一股股热浪扑人而来，马上就会要了人的性命。那黑红的烟
也毒的要命！洞窟四壁不断吞吐着火焰。
LONG
        );
        set("exits", ([ 
  "out" : "/d/qujing/firemount/shanbian",
]));
        set("objects", ([
                
       ]) );
        
        setup();
        
}

void init ()
{
  add_action ("do_around","around");
  add_action("do_study", "xiulian");
}

int do_around ()
{
  object me = this_player ();
  message_vision ("$N屏住呼吸，想四处转转。\n",me);  
  if(!me->query("m_success/火焰刀"))
  {
    message_vision ("$N被四周的热浪毒烟包围住，越来越透不过起来！\n",me);
    call_out("fainting",5,me);  
    return 1;
  }
  if(!me->query_skill("huoyan-hand", 1)){
  message_vision("$N躲闪着四周的火焰和毒烟，身法展动，居然悟出了一套拳法。\n",me);
  me->set_skill("huoyan-hand",1);}
  return 1;
}


void fainting (object me)
{
        message_vision("突然一个巨大的火焰舔中$N，$N顿时头重脚轻。。。\n", me);
        me->set("m_success/火焰刀",1);
        me->die();
}

int do_study()
{       
        object me=this_player();
        int sen_cost, kee_cost, force_cost, gain;

        if( me->is_busy() )
                return notify_fail("你忙的很，哪有功夫修炼！\n");
        if( me->is_fighting() )
                return notify_fail("现学现卖已来不及了！\n");
        if( (int)me->query_skill("literate", 1) < 40)
                return notify_fail("你文化太低！\n");
        if( (int)me->query_skill("unarmed", 1) < 40)
                return notify_fail("你还是先学基本拳脚功夫吧。\n");
        if( (int)me->query_skill("huoyan-hand", 1) >= 40)
                return notify_fail("你感觉火窟已经不适合修炼了。\n");
        if( (int)me->query("max_force") < 400)
                return notify_fail("你底气不足，练不了。\n");

        sen_cost = 45 - (int)me->query_int();
        if( (int)me->query("sen") < sen_cost )
                return notify_fail("你现在头晕脑胀，该休息休息了。\n");

        kee_cost = 45 - (int)me->query_con();
        if( (int)me->query("kee") < kee_cost )
                return notify_fail("你现在浑身无力，该休息休息了。\n");

        force_cost = 20;
        if( (int)me->query("force") < force_cost )
                return notify_fail("你现在已提不起气了，该休息休息了。\n");

        me->receive_damage("sen", sen_cost);
        me->receive_damage("kee", kee_cost);
        me->add("force", - force_cost);

        gain = (int)me->query("int")/2 + (int)me->query("con")/2 + 1 + random(10);

        me->improve_skill("huoyan-hand", gain);

        write("你躲闪着火焰毒烟，对『火焰刀』又有所了解。\n");

        tell_room( environment(me), me->name() + "身法轻灵，手脚怪异地舞动。\n", ({me}));

        return 1;
}
