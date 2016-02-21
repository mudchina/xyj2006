//zoulang.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "三楼：走廊");
        set("long", @LONG

走廊的尽头有扇桃木门，门后有间谈心室。
LONG
        );

        set("exits", ([
                "enter" : __DIR__"talkroom",
                "east" : __DIR__"living",
        ]));

        create_door("enter", "桃木门", "out", DOOR_CLOSED);

        setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object room, *person;
        int i, num;

        if ( !arg || (arg != "door" && arg != "enter") ) return 0;

        if ( !( room = find_object(__DIR__"talkroom") ) )
                room = load_object(__DIR__"talkroom");

        person = all_inventory(room);

        for ( i=0; i<sizeof(person); i++ ) {
                if ( person[i]->is_character() && userp(person[i]) ) num++;
        }

        if ( num >= 2 && room->query("locked") ) {
                write("房里有人，门正锁着呢！\n");
                return 0;
        }

        return 0;
}


