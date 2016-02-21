inherit BULLETIN_BOARD;

void create()
{
        set_name("柱子", ({ "zhuzi" }) );
        set("location", "/d/city/club3");
        set("board_id", "zhuzi_b");
	set("long", "柱子上用刀刻着几行大字：

这里是专门为打牌提供的，希望各位玩家不要把西游记里的恩恩怨怨
带到这里来。希望大家能了解，不要在这里打架斗殴、施法、读书、
或偷窃。又：我们不可能完全控制一切交谈频道，所以希望大家不要
透露手里的牌，而且打输了不要逃，以免玩得不愉快。

祝：牌运亨通！
——————————————————————————————\n");
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

