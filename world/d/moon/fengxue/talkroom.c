//talkroom

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "谈心室");
        set("long", @LONG

一间专供说悄悄话的交谈室。
LONG
        );

        set("exits", ([
                "out" : __DIR__"zoulang"
        ]));

        create_door("out", "桃木门", "enter", DOOR_CLOSED);

        setup();
}

void init()
{
        object *person, room = environment(this_player());
        int i, num;

        person = all_inventory(room);
                                
        for ( i=0; i<sizeof(person); i++ ) {
                if ( person[i]->is_character() && userp(person[i]) ) num++;
        }

        if ( num > 2 && room->query("locked") ) {
                this_player()->move(__DIR__"zoulang1");
                write("嘿嘿！门锁着哪，你进不去！\n");
        }

        add_action("do_lock", "lock");
//        add_action("do_open", "open");
}

/*
int do_open()
{
        object room = environment(this_player());

        room->delete("locked");
        return 1;
}
*/

int do_lock()
{
        object *person, room = environment(this_player());
        mapping exit;
        int i, num;
        string dir;

        if( !(doors["out"]["status"] & DOOR_CLOSED) )
                return notify_fail("门还没关上哪！\n");

        if ( room->query("locked") )
                return notify_fail("门正锁着哪！\n");
                                       
        person = all_inventory(room);
                                
        for ( i=0; i<sizeof(person); i++ ) {
                if ( person[i]->is_character() && userp(person[i]) ) num++;
        }                                                               
         
        if ( num < 2 ) 
                return notify_fail("房里只有你一个人，向谁说悄悄话呢？不必把门锁上吧。\n");
       
        room->set("locked", 1);
                               
        remove_call_out("unlock_door");
        call_out("unlock_door", 1800, room);
                                                                     
        message_vision("$N将门拴一旋一按锁好，满脸笑容的转过身来。\n", this_player());                                                           
        write("你数了数屋里一共" + num + "个人。\n");
        return 1;
}
                                                                                
                                                                        
int unlock_door(object room)
{
        room->delete("locked");
        write("门锁蹦的一声弹开了！\n");
        return 1;
}


