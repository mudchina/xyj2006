inherit __DIR__"piggy_two.c";

void create()
{
    ::create();

    set ("short", "Ë«ÈË¹°Öí·¿");
    set("exits", ([
        "west": __DIR__"club3",
    ]) );
}
