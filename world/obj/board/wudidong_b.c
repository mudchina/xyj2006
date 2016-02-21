// wudidong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("帐本", ({ "zhangben" }) );
        set("location", "/d/qujing/wudidong/kitchen.c");
        set("board_id", "wudidong_b");
        set("long", "这是无底洞的帐本，是厨子用来记下谁孝敬了新鲜人肉用的。\n");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
