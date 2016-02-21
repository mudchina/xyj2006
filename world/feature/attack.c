// attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#include "/cmds/std/valid_kill.h"
//check whether allow PK.

#define MAX_OPPONENT	4

static object *enemy = ({});
static object *netdead_enemy = ({});
static string *killer = ({});

// prototypes

object *query_enemy() { return enemy; }
object *query_netdead_enemy() { return netdead_enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 ) 
		enemy += ({ ob });
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
    object env=environment();

        if(!ob) return;
	
	// mon 8/2/98
	if(env && env->query("no_fight")
		&& env->query("no_magic")) return;

	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

	tell_object(ob, HIR "看起来" + this_object()->name() + "想杀死你！\n" NOR);

	fight_ob(ob);
}

void add_netdead_enemy()
{
	for(int i=0; i<sizeof(enemy); i++)  {
		netdead_enemy += ({ enemy[i] });
	}
}

void remove_netdead_enemy()
{
	for(int i=0; i<sizeof(netdead_enemy); i++)  {
		netdead_enemy[i] = 0;
	}
	netdead_enemy = ({});
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object ob;
	string type, skill;
	
	if ( ob = query_temp("weapon") )
	    type = ob->query("skill_type");
	else 
		type = "unarmed";

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

void reset_apply_action()
{
	object ob;
	string type, skill;

	if( ob = query_temp("weapon") )
	    type = ob->query("apply/skill_type");
	else 
		type = "unarmed";

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("apply/actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.
//private int attack()
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob, env=environment();
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.

	// 4/22/98
	// mon moved no_fighting check to here.
	if(env && (env->query("no_fight") || env->query("no_magic")))
		  return;

	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player()) 
	||	environment(ob)!=env
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

//whether player can auto kill is subject to valid_kill.
//mon 1/22/98
	// mon 8/7/98  don't modify my_killer_list
	if(!valid_kill(this_object(), ob,1)) return;

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} 

	else if( random((int)query("bellicosity") / 40) > (int)query("cps")) {
	    // mark my_killer_list in combatd/auto_fight.
		COMBAT_D->auto_fight(this_object(), ob, "berserk");
		return;
	} 
}
