
// toulu.c

inherit ITEM;

int decayed;

void create()
{
        set_name("无名头颅", ({ "toulu" }) );
        set("long", "这是一具无名头颅。\n");
        set("short","头颅");
        set("unit", "颗" );
        set_weight(100);
        decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 180, 1);
}

// int is_corpse() { return decayed < 2; }
// int is_character() { return decayed < 1; }
// int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }


void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + "开始腐烂了，发出一股难闻的恶臭。\n" );
                        switch(query("gender")) {
                                case "男性":{
                                        set_name("腐烂的男头颅", ({ "toulu", "头颅" }) );
                                                    break;
                                                         }
                                case "女性":{
                                        set_name("腐烂的女头颅", ({ "toulu", "头颅" }) );
                                                         break;
                                                         }
                                default:{
                                        set_name("腐烂的头颅", ({ "toulu", "头颅" }) );
                                                   break;
                                                    }
//by maxim jiang 1997.7.15

                        }
                        set("long","这个头颅显然已经在这里有一段时间了，正散发著一股腐烂的味道。\n");

                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        say( query("name") + "被风吹乾了，变成一具骸骨。\n" );
                        set_name("一具枯乾的头骨", ({ "tougu", "头骨" }) );
                        set("long", "这副头骨已经躺在这里很久了。\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        say( "一阵风吹过，把" + query("name") + "化成骨灰吹散了。\n" );
                        if( environment() ) {
                                object *inv;
                                int i;

                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) inv[i]->move(environment());
                        }
                        destruct(this_object());
                        break;
        }
}