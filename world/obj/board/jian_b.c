
inherit BULLETIN_BOARD;
void create()
{
        set_name(" 剑碑 ", ({ "jianbei" }) );
        set("location", "/d/sanxian/jianzhong.c");
        set("board_id", "jian_b");
     set("long",     "一块巨大的石碑,恰似一把长剑插入剑塚。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

