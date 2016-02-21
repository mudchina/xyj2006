inherit __DIR__"piggy.c";

void create()
{
    ::create();

    set ("short", "¹°ÖíÄÏ·¿");
    set("exits", ([
        "north": __DIR__"club3",
    ]) );
}
