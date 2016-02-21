inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{	int ratio;

        me->apply_condition("in_hell", -1);  

        if(environment(me)->query("hell") ) {
                me->apply_condition("in_hell", 1);
        } else {
		me->delete_temp("in_hell");
		return 1;
	}
        if( duration < 1 ){
		me->delete_temp("in_hell");
	 	return 0;
	}

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");
	if( !duration ) return 0;
    	if (ratio > 80) 
		tell_object(me, "你觉得头脑不大清醒，身子轻飘飘的。\n");
    	else if (ratio > 60) 
		tell_object(me, "你觉得脑袋又痛又涨，身子已不大听使唤了。\n");
    	else if (ratio > 40) 
		tell_object(me, "你觉得呼吸困难，眼前一切都模糊了起来。\n");
    	else 
		tell_object(me, "你昏昏欲睡，马上就要倒在地下了。\n");

    me->receive_wound("sen", 2);
    if (me->query("mana") < 0) me->set("mana", 0);

    return 1;
}

