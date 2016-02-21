// combined_item.c
// 4/25/98 mon changed move() so that money will be combined
// even at a non-living thing, eg, room.

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

static int amount;

void setup()
{
}

int query_amount() { return amount; }

private void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
    object dest;

	if( v < 0 ){
	   amount=0; // mon 4/16/98
	   call_out("destruct_me", 1);
	   error("combine:set_amount less than 1.\n");
	}
	if( v==0 ) {
	    amount = 0; // mon 4/16/98
	    seteuid(getuid());
	    dest=load_object("/cmds/std/quitroom");
	    if(environment(this_object())!=dest)
	      ::move(dest,1); // use the old move(), so
	    // that won't recursively call set_amount.
	    call_out("destruct_me", 1);
	}
	else {
		amount = v;
		this_object()->set_weight(v * (int)query("base_weight"));
	}
}

void add_amount(int v) { set_amount(amount+v); }

string short()
{
	return chinese_number(query_amount()) + query("base_unit")
		+ ::short();
}

varargs int move(mixed dest, int silent)
{
	object env, *inv;
	int i, total, total0, result;
	string file;

	result= ::move(dest, silent);
	if(env = environment()) {
		file = base_name(this_object());
		inv = all_inventory(env);
		total = (int)query_amount();
		total0=total;
		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]==this_object() ) continue;
			if( base_name(inv[i])==file ) {
				total += (int)inv[i]->query_amount();
				destruct(inv[i]);
			}
		}
		if(total!=total0)
		  set_amount(total);
	}
	return result;
}
