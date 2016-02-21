

inherit BULLETIN_BOARD;
void create()
{
        set_name(" 解剑池 ", ({ "swordchi" }) );
        set("location", "/d/shushan/paifang.c");
       set("long",     "只见剑池石壁上书: 飞天御剑流 。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

