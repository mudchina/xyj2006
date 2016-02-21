// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

static object leader, *team;

int set_leader(object ob)
{
	if( ob==this_object() )
		error("set_leader: Cannot set this_object() as leader.\n");
	leader = ob;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
        int backval;

	if( (origin()==ORIGIN_LOCAL) || (origin()==ORIGIN_CALL_OUT) ) {
		this_object()->remove_all_enemy();
                if (this_object()->query("id")=="qujing ren")
                        //blacksh 01/19 qujingren move need time
                  {  
                      if (this_object()->query("food")<20) return 1;
                      backval= GO_CMD->main(this_object(), dir);
                      OBSTACLE_D->set("where_qujingren",
                                base_name(environment(this_object())) );
                      this_object()->start_busy(2);
                      return backval;

                   }
                else
                   {
                   return GO_CMD->main(this_object(), dir);
                   }
	}
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;

	if( ob==leader
	||	(query("pursuer") && this_object()->is_killing(ob->query("id")))) {
		if( random(ob->query_skill("move")) > this_object()->query_skill("move") ) {
			remove_call_out("follow_path");
			call_out("follow_path", 1, dir);
			return 1;
		}
		return follow_path(dir);
	}
}

int add_team_member(object ob)
{
	if( ob==this_object() ) return 0;

	if( arrayp(team) ) {
		if( member_array(ob, team)==-1 ) {
			team -= ({ 0 });
			team += ({ ob });
			for(int i=sizeof(team)-1; i>=0; i--)
				team[i]->set_team(team);
		} else
			return 0;
	} else {
		team = ({ this_object(), ob });
		ob->set_team(team);
	}
	return 1;
}

int is_team_leader()
{
	return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
	team = t;
}

varargs int dismiss_team(object ob)
{
	int i;

	if( !arrayp(team) ) return 0;
	
	if( !ob ) {
		if( team[0]==this_object() ) {
			team -= ({ 0 });
			for(i=1; i<sizeof(team); i++)
				team[i]->set_team(0);
		} else {
			team -= ({ 0 });
			for(i=0; i<sizeof(team); i++)
				team[i]->dismiss_team( this_object() );
		}
		team = 0;
	} else
		team -= ({ ob });

	return 1;
}

object *query_team()
{
	return team;
}



