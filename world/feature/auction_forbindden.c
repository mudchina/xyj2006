string query_type(object me) { return "job"; }

int update_condition(object me, int duration)
{
	me->apply_condition("auction_forbindden", duration - 1);
	if( duration < 1 ) return 0;
	return 1;
}
