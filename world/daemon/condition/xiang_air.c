//Longgong_hot.c
int update_condition(object me, int duration)
{
        int limitmana, limitsen, limitkar;
	int mymana, mysen, mykar;
	int success;

	limitmana = 800;
	limitsen = 1000;
	limitkar = 30;

	mymana = (int)me->query("max_mana");
	mysen = (int)me->query("max_sen");
	mykar = (int)me->query_kar();

	success = 1;

	if( mymana > random(limitmana+mymana) ) success=0;
	if( mysen  > random(limitsen+mysen)   ) success=0;
	if( mykar  > random(limitkar+mykar)   ) success=0;

        tell_object(me, "你觉得鼻子里面痒痒的，打了个大喷嚏。\n");
        tell_room(environment(me), me->name()+"使劲地打了个喷嚏！\n", ({me, me}));

	if ( !success ) {

		me->receive_damage("sen", mysen/10);
		me->add("mana", -mymana/10);

	} else {

		me->unconcious();

	}

	me->apply_condition("xiang_air", duration-1);

        if( !duration ) return 0;
        return 1;
}

