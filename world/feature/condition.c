// condition.c

#include <condition.h>

mapping conditions;

// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.

nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {

		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		cnd_d = find_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) {
//        err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));

			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.

			if( err || !cnd_d ) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				map_delete(conditions, cnd[i]);
				continue;
			}
		}

		// We assume since the condition daemon is loaded successfully, the
		// calling on its update_condition() should success as well. Because
		// catch() is somewhat costly, so we don't attempt to catch possible
		// error from the call_other. It is condition daemon's reponsibility
		// that don't cause error in users's heart beat.
		// If condition daemon returns 0 (or update_condition() not defined),
		// we can just assume the condition expired and remove it.
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( !( flag & CND_CONTINUE ) ) {
		    // 3/31/99 check again whether has condition.
		    if(conditions) map_delete(conditions, cnd[i]);
		    else break;
		}

		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;

	return update_flag;
}

// apply_condition()
//
// This function applies the specific condition to the character. Note we 
// don't check if the condition already exist before setting condition info.
// It is condition giver's reponsibility to check if the condition should
// override the old one if same condition already exists.(Use query_condition
// to check)

nomask void apply_condition(string cnd, mixed info)
{
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}

// query_condition()
//
// This function returns info about the specific condition if any.

nomask mixed query_condition(string cnd)
{
    if(!cnd) return conditions;

	if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
	return conditions[cnd];
}

// mon 8/1/98
nomask void clear_condition(string name)
{
	mixed *cnd;
	int i;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	
	if(name) { // only clear this one condition.
	    map_delete(conditions, name);
	    if( !sizeof(conditions) ) conditions = 0;
	    return;
	}

	cnd = keys(conditions);

	while(i--) {
	  cnd_d = load_object(CONDITION_D(cnd[i]));
	  if(!cnd_d) {
	      map_delete(conditions, cnd[i]);
	      continue;
	  }

	  if(!(cnd_d->no_clear_condition()))
	      map_delete(conditions, cnd[i]);
	}

	if( !sizeof(conditions) ) conditions = 0;
}
 
