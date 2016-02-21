// emoted.c
// modified by none on 96/10/04
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for 
//          intermud emote.

#include <ansi.h>
#include "/cmds/std/block_tell.h"  //mon 9/15/97
                                   //prevent flooding by emote.

inherit F_SAVE;

mapping emote;

//	The emote mapping contains the data base of emote definitions. Each emote
//	is defined in a sub-mapping with the following structure:
//
//	myself	- the message emoter will see
//	target	- the message the target will see when targeted
//	others	- the message others will see when no argument.
//
//	The emote mapping is indexed with the emote 'pattern' instead of emote
//	verb. For example, typing "smile" without argument will cause the daemon
//	search the emote mapping with "smile" as key, and typing "smile someone"
//	will cause the daemon search the emote mapping with "smile $" pattern as
//	the key, while $ means one argument.
//
//	In the message string, the following substitutions will be applied before
//	sending the messages:
//
//	$N		- name of emoter
//	$n		- name of target
//	$P		- pronoun of emoter
//	$p		- pronoun of target
//
//	Original by Annihilator@ESII (11/09/94)
//      $C              - respect call of emoter
//      $c              - rude call of emoter 
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      added by none on 96/10/04 

void create()
{
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote, int rumor_emote, int intermud)

// intermud portion added by mon. 10/1/97
{
	string str, my_gender, target_gender, msg_postfix;
	object target;
	string if_execute;
	string user_emote;

	if( !environment(me) ) return 0;

//	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;
	if ( !mapp(emote) ) return 0;
	if(undefinedp(emote[verb])) {
		if(!channel_emote)  return 0;
		if(verb[0] < 0x80)  return 0;
		if(rumor_emote)
		   user_emote = "某人" + verb + "\n";
                else {
                  if(!channel_emote || ! intermud)
		     user_emote = me->name() + verb + "\n";
                  else
		     user_emote = "$N" + verb + "\n";
                }
	    return user_emote;
	}

	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != "" ) {
		target = present(arg, environment(me));

		notify_fail("你要对谁做这个动作？\n"); 
		
		if(!objectp(target)) {
			// If not channel emote, only search target in our environment.
			if(!channel_emote) return 0;
			target = find_player(arg);
			if( !objectp(target) ) return 0;
		}
		
		if( !target->is_character() || !me->visible(target) )
			return 0;

		// prevent doing emotes on invisible wiz.
		// but can do channel emotes.
		// mon 7/6/98
		if( wizardp(target) &&
			target->query("env/invisibility") &&
			!channel_emote )
		    return 0;

		target_gender = target->query("gender");
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

//mon 9/15/97. for emote flooding.
        if(!channel_emote) {
          if(!block_tell(me)) return 1;
	}

	my_gender = me->query("gender");

	if_execute = "";
	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		if_execute = " ";
		if(rumor_emote)
		   str = replace_string(str, "$N", "某人");
        else
		   str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_respect(me));
                        str = replace_string(str, "$c", RANK_D->query_rude(me));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		//if( !channel_emote ) message("emote", CYN + str + NOR, me);
		if( !channel_emote ) message("emote", CYN + str + NOR, me);
	}
  
	if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
		if_execute = " ";
		if(rumor_emote)
		   str = replace_string(str, "$N", "某人");
        else
		   str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_respect(me));
                str = replace_string(str, "$c", RANK_D->query_rude(me));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
		str = replace_string(str, "$n", target->name());
		str = replace_string(str, "$p", gender_self(target_gender));

		if( !channel_emote ) message("emote", CYN + str + NOR, target);
	}

	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
		if_execute = " ";
		if(rumor_emote)
		   str = replace_string(str, "$N", "某人");
        else if(!channel_emote || !intermud)
		   str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
                        str = replace_string(str, "$C", RANK_D->query_respect(me));
                        str = replace_string(str, "$c", RANK_D->query_rude(me));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ) {
			 message("emote", CYN + str + NOR, environment(me), ({me, target}));
			 if (environment(me)->query("broadcast"))
			 	environment(me)->broadcast(CYN + str + NOR);
		} else return str;
	}
if(objectp(target)) {
 if(!living(target)) write(HIW"但是很显然，"+target->name(1)+"现在的状态没法给你任何答复。\n"NOR);
 else if (interactive(target)&&query_idle(target)>300) write(YEL+"但是"+target->name(1)+"已经发呆"HIR+chinese_number(query_idle(target)/60)+NOR YEL"分钟，看来不会有反应了！\n"NOR);

   }
	// Let NPC know we are doing emote on him.
	if( objectp(target) ) target->relay_emote(me, verb);

	if(if_execute == "")   return 0;
	return 1;
}

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}
