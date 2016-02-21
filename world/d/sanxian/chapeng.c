// edited by mind
inherit ROOM;

void create()
{
        set("short", "茶棚");
        set("long", @LONG
鹅卵石路边，有贩子搭了一座茶棚，摆了几张木桌，几条长凳，正在
做些卤味小吃，阳春白面的生意。茶棚下，停着叁辆华丽的大车，几匹鞍
辔鲜明的健马，几个锦衣华服的少年，正在招手。
LONG
        );
        set("exits", ([ 
                "north" : "/d/kaifeng/chen1",
        ]));
     set("objects", ([
        
       ]) ); 
        
        setup();
        replace_program(ROOM);
}
