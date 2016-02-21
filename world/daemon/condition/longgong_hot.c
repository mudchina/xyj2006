//Longgong_hot.c
int update_condition(object me, int duration)
{
        int limit, shaqi;

        limit = (int)me->query("cor")*50 + (int)me->query("max_force");
	shaqi = (int)me->query("bellicosity");

        me->apply_condition("longgong_hot", duration - 1);

        if( shaqi > limit
        &&      living(me) ) {
                me->unconcious();
        } else if( !living(me) ) {
message("vision", me->name() + "嘴里喷出股浓烟，却依然昏迷不醒。\n",environment(me), me);
		return 0;
        } else if( shaqi > limit/2 ) {
                tell_object(me, "你觉得腹内如火燎一般，随是要炸开一样。\n");
                message("vision", me->name() + "一张嘴，似乎吐出几颗火星，辟辟乱迸。\n",environment(me), me);
                me->receive_damage("sen", 30);
		me->add("bellicosity", 30);
        } else if( shaqi > limit/4 ) {
                tell_object(me, "你觉得如同火炉一般烧的难受。\n");
                message("vision", me->name() + "嘴里冒出淡淡几许黑烟。\n",environment(me), me);
                me->receive_damage("sen", 20);
		me->add("bellicosity", 20);
        } else {
		tell_object(me, "你觉得腹内象有一团火在烧一样。\n");
                message("vision", me->name() + "头上冒出丝丝白烟。\n",environment(me), me);
                me->receive_damage("sen", 10);
                me->add("bellicosity", 10);
	}

	me->add("potential", 10);

        if( !duration ) return 0;
        return 1;
}

