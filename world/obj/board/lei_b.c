
inherit BULLETIN_BOARD;
void create()
{
        set_name("  泪石  ", ({ "leishi" }) );
        set("location", "/d/pansi/damen");
        set("board_id", "lei_b");
  set("long", "一块大石头，上书“情为何物”
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

