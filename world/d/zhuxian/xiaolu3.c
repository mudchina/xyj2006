inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你走在一条羊肠小路上，前面隐隐约约可以看到厮杀的场面。
LONG);
        set("exits", ([
                "northeast" : __DIR__"xiaolu2",
                "east" : __DIR__"xiaolu4",
        ]));
        setup();
}
