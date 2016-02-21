inherit NPC;

void create()
{
       set_name("小学童", ({ "xuetong" }));
       
set("long","小学童背不了书，正被教书先生罚站．\n");
       set("gender", "男性");
       set("age", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("combat_exp", 237);
setup();
// carry_object("/u/dream/obj/cloth")->wear();
add_money("coin", 10);
}

