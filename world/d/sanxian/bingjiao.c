// writted by mind

inherit ROOM;
void create()
{
        set("short", "冰窖");
        set("long", @LONG
这是西梁女儿国的一个巨大冰窖，原来用来为皇家储藏珍贵食物的，
现在虽然已经荒废，但是里面的冰块依然堆得满满的，四周墙壁已经结
了厚厚的冰。无数冰凌闪着刺眼的光，这么个寒冷的地方，寒气已经透
不出去，积年日久，已经极其寒冷，里面恐怕半个时辰都呆不了。
LONG
        );
        set("exits", ([ 
  "out" : "/d/qujing/nuerguo/shanpo",
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
  message_vision ("$N浑身哆嗦着，抵御周围的寒气。\n",me);  
  if(!me->query("m_success/冰魄刀"))
  {
    message_vision ("$N的衣服似乎也开始结冰！\n",me);
    call_out("fainting",5,me);  
    return 1;
  }
  if(!me->query_skill("bingpo-hand", 1)){
  message_vision("$N使劲顿脚舞手，不停地运内息抵御寒气，居然悟出了一套拳法。\n",me);
  me->set_skill("bingpo-hand",1);}
  return 1;
}


void fainting (object me)
{
        message_vision("突然$N嘴唇发青发紫，脸色苍白，一个踉跄倒在地上。。。\n", me);
        me->set("m_success/冰魄刀",1);
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
        if( (int)me->query_skill("bingpo-hand", 1) >= 40)
                return notify_fail("你感觉冰窖已经不适合修炼了。\n");
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

        me->improve_skill("bingpo-hand", gain);

        write("你施展拳脚，催动内息，对『冰魄刀』又有所了解。\n");

        tell_room( environment(me), me->name() + "身法轻灵，手脚怪异地舞动。\n", ({me}));

        return 1;
}
