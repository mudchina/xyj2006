int update_condition(object me, int duration)
{
                                                
        me->receive_wound("sen", 10);
        me->receive_wound("kee", 10);
        me->set_temp("death_msg","瘟病发作死了。\n");
        me->apply_condition("jjf_poison", duration - 1);

        if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
                message_vision("$N浑身颤个不停，似乎随时都会倒下去。\n", me);
        else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
                message_vision("$N面目浮肿，嘴中不断流出黄沫。\n", me);
        else 
                message_vision("$N脸色发黄，四肢颤个不停。\n", me);

        if( duration < 1 ) return 0;
        return 1;
}

