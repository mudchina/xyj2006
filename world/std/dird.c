static mapping opp_dir = ([
  "east"        :       "west",
  "west"        :       "east",
  "north"       :       "south",
  "south"       :       "north",
  "northeast"   :       "southwest",
  "southwest"   :       "northeast",
  "northwest"   :       "southeast",
  "southeast"   :       "northwest",
  "northup"     :       "southdown",
  "southup"     :       "northdown",
  "eastup"      :       "westdown",
  "westup"      :       "eastdown",
  "northdown"   :       "southup",
  "southdown"   :       "northup",
  "eastdown"    :       "westup",
  "westdown"    :       "eastup",
  "up"          :       "down",
  "down"        :       "up",
]);

static mapping chinese_dir = ([
        "north":                "北边",
        "south":                "南边",
        "east":                 "东边",
        "west":                 "西边",
        "northup":              "北上方",
        "southup":              "南上方",
        "eastup":               "东上方",
        "westup":               "西上方",
        "northdown":        "北下方",
        "southdown":        "南下方",
        "eastdown":             "东下方",
        "westdown":             "西下方",
        "northeast":        "东北方",
        "northwest":        "西北方",
        "southeast":        "东南方",
        "southwest":        "西南方",
        "up":                   "上面",
        "down":                 "下面",
        "out":                  "外面",
]);

static mapping abbr_dir = ([
        "n"     :       "north",
        "s"     :       "south",
        "e"     :       "east",
        "w"     :       "west",
        "nu"    :       "northup",
        "su"    :       "southup",
        "eu"    :       "eastup",
        "wu"    :       "westup",
        "nd"    :       "northdown",
        "sd"    :       "southdown",
        "ed"    :       "eastdown",
        "wd"    :       "westdown",
        "ne"    :       "northeast",
        "nw"    :       "northwest",
        "se"    :       "southeast",
        "sw"    :       "southwest",
        "u"     :       "up",
        "d"     :       "down",
        "o"     :       "out",
]);

string abbrdir(string dir)
{
  if (!undefinedp(abbr_dir[dir]))
    return abbr_dir[dir];
  else
    return dir;
}

string cdir(string dir)
{
  dir = abbrdir(dir);
  if (!undefinedp(chinese_dir[dir]))
    return chinese_dir[dir];
  else return dir;
}

string oppdir(string dir)
{
  if (!undefinedp(opp_dir[dir]))
    return opp_dir[dir];
  else
    return "";
}
