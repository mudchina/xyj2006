inherit NPC;
string send_mail();
string receive_mail();

void create()
{
        set_name("╢Внджь", ({"dai wenzhong", "dai"}));
        set("age", 42);
        set("gender", "дппт");
        set("long",
"ФДу╬юО╣д╣╠╪рё╛Ё╓╣дт╡т╡ежеж╣д║ё\n");
	set("title", "ФДу╬╣╠╪р");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
  set("daoxing", 20000);

        set("shen_type", 1);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 40);
        set("inquiry", ([
                "╥╒пе" : (: send_mail :),
                "йупе" : (: receive_mail :),
                "пе╪Ч" : (: receive_mail :),
                "пе" : (: receive_mail :),
                "mail" : "дЗ╫╡╣дйгмБ╧З╩╟╟иё©нрлЩ╡╩╤╝р╝~~~~~~~~",
        ]) );

	setup();
        carry_object(__DIR__"obj/choupao")->wear();
}
string send_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "дЦ╣дпеоД╩╧тз╟иё©сцпеоД╬м©ирт╪дпеак║ё\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "╣хр╩об╣╫ФДу╬ю╢урнр╟и║ё\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "е╤...
р╙╪дпейгбПё©уБйгдЦ╣дпеоДё╛╪дпе╣д╥╫╥╗пеоДиоспк╣цВ║ё\n";
}

string receive_mail()
{
        object mbox;

        if( this_player()->query_temp("mbox_ob") )
                return "дЦ╣дпеоД╩╧тз╟иё©дЦкЫсп╣дпе╤╪тзюОцФ║ё\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "╣хр╩об╣╫╢Сй╞м╥ю╢урнр╟и║ё\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return
"╨цё╛╢Щнрурур....спакё╛дЦ╣дпеоДтзуБё╛бЩбЩ©╢╟иё╛╡╩╢Р╫адЦак║ё\n";
}

Ъ