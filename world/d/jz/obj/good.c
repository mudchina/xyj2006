//Cracked by Roath
inherit ITEM;

string *names = ({
        "鸟毛",
        "猪毛",
        "猪皮",
        "大石头",
        "树枝",
        "死老鼠",
        "西瓜皮",
        "破布头",
        "鸡毛",
        "蒜皮",
        "杂草",
        "用过的牙签",
        "断笔",
});

string *ids = ({
        "niao mao",
        "zhu mao",
        "zhu pi",
        "big stone",
        "shu zhi",
        "dead mouse",
        "xigua pi",
        "po butou",
        "ji mao",
        "suan pi",
        "zao cao",
        "used yaqian",
        "duan bi",
});

string *units = ({
        "根",
        "根",
        "块",
        "块",
        "根",   
        "个",
        "块",
        "块",
        "根",
        "块",
        "团",
        "根",
        "支",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit",units[i]);
  set("value",5);
  setup();
}
