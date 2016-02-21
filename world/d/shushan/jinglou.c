inherit ROOM;

/*string* books = ({
        "daodejing-i",
        "daodejing-i2",
        "daodejing-i3",
});*/

void create()
{
        set("short", "经楼");
        set("long", @LONG
这里是蜀山的经阁，蜀山武功从来口耳相
传，所以并没有什么太多的古籍，几个剑童悠
闲的擦拭着书架
LONG
        );

        set("exits", ([
                "west" : __DIR__"square",
        ]));

        set("objects", ([
                __DIR__"npc/jiantong" : 1,
//              __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/yijing" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
