// corpse.c

inherit ITEM;

int decayed;
int do_mai(string);

void create()
{
	set_name("无名尸体", ({ "corpse" }) );
	set("long", "这是一具无名尸体。\n");
	set("unit", "具" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			say( query("name") + "开始腐烂了，发出一股难闻的恶臭。\n" );
			switch(query("gender")) {
				case "男性":
					set_name("腐烂的男尸", ({ "corpse", "尸体" }) );
				case "女性":
					set_name("腐烂的女尸", ({ "corpse", "尸体" }) );
				default:
					set_name("腐烂的尸体", ({ "corpse", "尸体" }) );
			}
			set("long",	"这具尸体显然已经躺在这里有一段时间了，正散发着一股腐尸的味道。\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "被风吹干了，变成一具骸骨。\n" );
			set_name("一具枯干的骸骨", ({ "skeleton", "骸骨" }) );
			set("long", "这副骸骨已经躺在这里很久了。\n");
			set("is_skeleton",1);
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			say( "一阵风吹过，把" + query("name") + "化成骨灰吹散了。\n" );
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) {
				    inv[i]->move(environment());
				}
			}
			destruct(this_object());
			break;
	}
}

object animate(object who, int time)
{
	object zombie;

	if( !environment() ) return 0;

	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "的僵尸", ({ "zombie" }) );
	zombie->move(environment());
	zombie->animate(who);

	destruct(this_object());
	return zombie;
}
void init()
{                                             
        add_action("do_mai", "mai");
	add_action("do_mai", "bury");
}

int do_mai(string arg)
{
        object me = this_player();
  object *inv=all_inventory(this_object());
        if (!id(arg))
                return notify_fail("你要埋什么？\n");
	if(!environment(me)->query("mai_corpse_able"))
		return notify_fail("你不能在这里埋尸体！\n");
         destruct(this_object());

	if( random(3)==1) {
	me->add("potential", 1);
	}
	if( random(3)==1) {
	me->add("daoxing", random(3));
	}
	if(me->query("bellicosity")>10) me->add("bellicosity", -10);
	me->receive_damage("kee", 5);
	me->add("bury_corpse", 1);

	message_vision("$N在地下刨了个坑，把$n放了进去，用土埋了起来。\n", me, this_object());
        message_vision("$N对坟头鞠了个躬，道：怪你前世命短，好好修来生去吧！\n", me);
  for(int i=0;i<sizeof(inv);i++) {
    destruct(inv[i]);
  
  }
        return 1;
}

