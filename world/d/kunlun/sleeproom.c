inherit ROOM;

void create ()
{
        set ("short", "休息室");
        set ("long", @LONG

玉虚洞的弟子休息室。陈设相当简陋，连张床都没有。
LONG);

        //set("item_desc", (["bed" : "一张精致的床铺(gosleep, gobed, bed)。\n", ]));
        //for look something.

        set("exits", 
        ([ //sizeof() == 4
                "northwest" : __DIR__"lingyunge",
                
        ]));
        
        set("sleep_room",1);      

        setup();
}
