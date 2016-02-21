// xuy
#include <ansi.h>
inherit ROOM;

int query_max_items() {return 100000;}
int do_quit();
void clear_item();

void create()
{
	set("short", "");
	set("long", @LONG
LONG
	);

	setup();
}

void init()
{
	if (!wizardp(this_player())){ 
	     add_action("do_quit","",1);
	     call_out("force_quit",1,this_player());
	     //use delayed quit to avoid the error message
	     //in debug.log due to this_player is destructed
	     //before the move() is finished.
	     // mon 8/17/97
	}
}

int do_quit()
{
    object me=this_player();
    if(query_verb()=="quit") return 0;
    this_player()->force_me("quit");
    clear_item();
    if(me) destruct(me);
    return 1;
}

void force_quit(object me)
{
   if(me) me->force_me("quit");
   clear_item();
   if(me) destruct(me);
}

void clear_item()
{
    object *obj=all_inventory(this_object());
    int size;
    
    size=sizeof(obj);
    while(size--) {
	if(!obj[size]) continue;
	if(!userp(obj[size]))  destruct(obj[size]);
    }
}
    
