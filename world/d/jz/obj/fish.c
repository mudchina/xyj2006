//Cracked by Roath
inherit ITEM;

string *names = ({
  "[33mĞ¡ÏºÃ×[m",
  "[31mĞ¡ÓãÃç[m",
  "[32mĞ¡òòò½[m",
  "[33m±´¿Ç[m",
  "[34mĞ¡Óã[m",
  "[35mĞ¡Éß[m",
  "[36mĞ¡ÎÚÔô[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"fish"}));
  set("unit","Ìõ");
  set("value",50);
  setup();
}
