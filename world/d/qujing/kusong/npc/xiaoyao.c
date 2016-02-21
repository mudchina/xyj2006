//Cracked by Roath
inherit NPC;

void create()
{
  set_name("Ð¡Ñý", ({"xiao yao","yao"}));
  set("gender", "ÄÐÐÔ");
  set("age", 10);
  set("long","Ò»¸öÔôÃ¼ÊóÑÛµÄÐ¡Ñý¾«¡£\n");
  set("combat_exp", 10000+random(3000));
  set("daoxing", 10000);

  set("per", 15);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set_skill("unarmed", 10);
  set("max_sen",200);
  set("max_gee",200);
  set("max_gin",200);
  set_skill("spells",10);
  set_skill("stick",10);
  set("chat_chance",2);
  set("chat_msg",({
        "Ð¡ÑýÖåÒ»ÖåÐ¡ÔôÃ¼¡£\n",
        "Ð¡ÑýÆ´ÃüµØÕ£Õ£Ò»¶ÔÉÁÉÁ·¢¹âµÄÐ¡ÊóÑÛ¡£\n",
        "Ð¡ÑýÒ»Ìø£¬°Èß´Ò»ÉùË¤ÔÚµØÉÏ¡£\n",
        "Ð¡Ñý×ßµ½ÄãÃæÇ°£¬ÍÛÑ½ßÞ°¡½ÐÁË¼¸Éù¡£\n",
        "Ð¡Ñýà²µØÒ»Éù£¬Ë¦ÊÖµ¹¹ÒÔÚ¶´ÑÒÉÏ¡£\n",
        "Ð¡ÑýÒ»²»Ð¡ÐÄ£¬Ñ½Ñ½Ñ½´Ó¶´ÑÒÉÏÊ§ÊÖµôÏÂÀ´¡£\n",
    }));
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/stick/shuzhi")->wield();
}

ÿ