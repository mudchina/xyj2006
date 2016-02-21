// skill.c

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
	
	if( !mapp(learned) ) learned = ([ skill: 0]);
		else if(undefinedp(learned[skill]))
		    (int)learned[skill] = 0;

}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}
varargs int query_max_mana()
{
                int s, bonus;
                s = 0;
                if( mapp(skills) ) {
                        s += skills["spells"] / 2;
                        if( mapp(skill_map) )
                                s += skills[skill_map["spells"]];
                }
                s = s * 10;
//              bonus=...
//              s = s + bonus;

                return s;
}

varargs int query_max_force()
{
		int s, bonus;
                s = 0;
                if( mapp(skills) ) {
                        s += skills["force"] / 2;
                        if( mapp(skill_map) )
                                s += skills[skill_map["force"]];
                }
		s = s * 10;
//		bonus=...
//		s = s + bonus;

                return s;
}

varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s;
		
		s = query_temp("apply/" + skill);
		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
				s += skills[skill_map[skill]];
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	return 0;
}

int add_maximum_mana(int amount)
{
    int j=query("maximum_mana");
    
    j=j+amount;
    // note: here if (j>query_max_mana()) can't set 
    // maximum_mana to query_max_mana().
    // because that might not be the maximum possible
    // number the player can get. (may use another
    // spells to get higher). so here return fail.
    if(j>query_max_mana()) return 0;
    else if(j<0) j=0;

    set("maximum_mana",j);
    set("max_mana",j); // note here j always <= query_max_mana()
                       // so no problem to set max_mana = j.
    set("mana",0);
    return 1;
}

int add_maximum_force(int amount)
{
    int j=query("maximum_force");
    
    j=j+amount;
    if(j>query_max_force()) return 0;
    else if(j<0) j=0;

    set("maximum_force",j);
    set("max_force",j);
    set("force",0);
    return 1;
}

mapping query_skill_map()
{
	return skill_map;
}

int skill_death_penalty()
{
	string *sk;
	int i;

	if( wizardp(this_object()) || !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++) {
			skills[sk[i]]--;
			if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				map_delete(learned, sk[i]);
			else {
				skills[sk[i]]--;
				if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
			}
		}
	skill_map = 0;

        if(userp(this_object()))
	  log_file("death",sprintf("[%s] %s lost skill.\n",
	         ctime(time()),this_object()->query("id")));
	return 1;
}

int skill_death_recover()
{
   
	string *sk;
	int i, amount;

	if( !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )  {
		learned = ([]);
		for(i = 0; i<sizeof(sk); i++) {
			amount = (skills[sk[i]]+1) * (skills[sk[i]]+1) * 3 / 4;
			learned += ([ sk[i] : amount ]); 
		}
    }	
	else  {
		for(i = 0; i<sizeof(sk); i++) {
			if( undefinedp(learned[sk[i]]) )  {
			    amount = (skills[sk[i]]+1) * (skills[sk[i]]+1) * 3 / 4;
				learned += ([ sk[i] : amount ]);
			}
			else {
				skills[sk[i]]++;
			}
		}
    }	
	return 1;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi;

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	// Give learning penalty to those learning too much skills.
	spi = query("spi");
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 0;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( (!weak_mode || !userp(this_object()))
	&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_object(), HIC "你的「" + to_chinese(skill) + "」进步了！\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}
}

