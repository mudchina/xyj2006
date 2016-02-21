#include <ansi.h>

inherit NPC;

int reset_status();

void init()
{
	::init();
	add_action("do_train", "train");
        
        remove_call_out("check_id");
        call_out("check_id",2);
        
 }

void check_id()
{
        
        object who,*enemy;
        object me = this_object();
        object rider_obj = me->query_temp("rider");
        int i,diff;
        string owner_id = query("owner");
        
// 没训
        if(!rider_obj)
        {
           remove_call_out("check_id");
           call_out("check_id",2);
           return ; 
        }
        
        if(!owner_id) 
        {
         	remove_call_out("check_id");
                call_out("check_id",10);
        	return ; 
        	} ;
//人不在
        who = present(owner_id, environment(me));
        if(!objectp(who)||!living(who))
        {
         	remove_call_out("check_id");
                call_out("check_id",4);
        	return ; 
        	} ;
// 没骑        
        	
       if(rider_obj->query("name")!=(string)who->query("name"))
       {
       	 	remove_call_out("check_id");
                call_out("check_id",4);
        	return ; 
      	} ;
        
        
        enemy=who->query_enemy();
        if (!enemy||who->is_fighting()==0)
        {
//                  if(me->is_fighting()==1)
//                  me->remove_all_killer();
                  remove_call_out("check_id");
                  call_out("check_id",4);
        	  return ; 
        } ;
               
        
        i=sizeof(enemy);
        while(i--) {
               if( enemy[i] && living(enemy[i]) ) {
       
       diff=50-who->query_kar();
       
       if(random(diff*diff) < 20 ) {
        message_vision(HIW "突然$N"+HIW"身上放出耀眼的九色毫光,$n惊呆了竟然忘了自己还在战斗中\n" NOR, me, enemy[i]); 
                   enemy[i]->start_busy(random(5));
               }}
        } 
    	        remove_call_out("check_id");
                call_out("check_id",2);
        	return ; 
   
}

int do_train(string arg)
{
	object me, where;
	me=this_player();
	where=environment(me);
/*
	if( where->query("no_fight") )
		return notify_fail("安全区内不能训兽！\n");
*/
	if( !arg )
		return notify_fail("你要驯服什么？\n");
	if( arg != (string)this_object()->query("id") )
		return notify_fail("你要驯服什么？\n");
	if( this_object()->query_temp("rider") )
		return notify_fail("这匹坐骑上已经有人了。\n");
	if( (string)this_object()->query("owner")==(string)me->query("id") )
		return notify_fail("这匹坐骑已经是你的了。\n");
	if( this_object()->is_fighting() )
		return notify_fail("这匹坐骑已经分身不暇了。\n");
	if( !living(this_object()) )
		return notify_fail("现在耍什么威风？\n");
	if( where->query("no_fight") ) {
		random_move();
		return 1;
	}


	message_vision(HIM"$N冲上前去和$n扭打成一团。\n"NOR, me, this_object());

       	this_object()->set_temp("owner",me->query("id"));
	reset_status();
	this_object()->kill_ob(me);
	me->fight_ob(this_object());

	return 1;
}

void unconcious()
{
        string owner;
        object owner_ob;
        owner = query_temp("owner");	
	
	if( owner ) {
	
	owner_ob= find_player(owner);
	
	if( objectp(owner_ob = find_player(owner)) ) {
	        if( (object)query_temp("last_damage_from") == owner_ob ) {
			set("owner", owner_ob->query("id"));
			delete_temp("owner");
			reset_status();
			this_object()->remove_all_killer();
			this_object()->set("attitude", "heroism");
			message_vision(HIY"\n$N低头缩尾，以示降服。\n"NOR, this_object());
			return;
        	}
	}
	}
//	message_vision(HIY"$N run away!\n"NOR, this_object());
	die();
//	::unconcious();
}



int reset_status()
{
	object me=this_object();
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));

	return 1;
}


