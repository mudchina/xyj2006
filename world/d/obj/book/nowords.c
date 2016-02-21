// nowords.c
//cglaem...12/16/96.

inherit ITEM;

void init();
void tear();

void create()
{
        set_name("〖无字天书〗", ({"book","nowords","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"一本脏兮兮的小册子。上面划着一些象是蚯蚓爬出来的图案。\n");
        set("material", "paper");
        set("value", 0); // reduced price because now shop's selling
	// price variable.
        set("skill", ([
                        "name": "spells",
                        "dx_required": 50,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill": 40,
]) );
        }
	setup();
}

void init()
{
        add_action("do_tear", "tear");
}

int do_tear(string arg){
	object ob,me;
	me=this_player();
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/magic/bishuizhou");
	ob->move(me);
	message_vision("$N撕开无字天书的背页，从里面小心翼翼地取出一张小纸片。\n", me);
	destruct(this_object());
	return 1;		
}

