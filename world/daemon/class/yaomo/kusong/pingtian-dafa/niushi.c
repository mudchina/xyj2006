// niushi.c
inherit SSERVER;
int cast(object me, object target)
{
 int invocation_time,k,i;
        object soldier;
        if(me->query("family/family_name")!="火云洞")
return notify_fail("你身上有没有牛虱，召什么啊！\n");

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤牛虱！\n");
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
	    return notify_fail("你身上年轻力壮的虱子已经都来帮你了！\n");
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");
message_vision("$N象吃了摇头丸一样，狂抖了几下。\n\n", me);
me->add("mana", -80);
me->receive_damage("sen", 100);
if( random(me->query("max_mana")) < 50 ) {
                message("vision", "但是什么也没有发生。\n",
environment(me));
                return 1;
}
k=(int)me->query_skill("pingtian-dafa")/20;
if (k>5) k=5;
for (i=1;i<=k;i++)
{
        seteuid(getuid());
        soldier = new("/obj/npc/niushi");
        soldier->move(environment(me));
        soldier->invocation(me);
soldier->set_temp("invoker",me);
}
        me->set("last_invocation",time());
	me->start_busy(2+random(2));
        return 8+random(5);
}
