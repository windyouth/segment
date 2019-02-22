#include "xml.h"
#include <stdio.h>
#include <assert.h>

//加载xml文件
xml_node *xml_load(const char *path)
{
    //参数校验
    assert(path);
    if (!path) return NULL;

    //打开文件
    FILE *fp = fopen(path, "r");
    if (!fp) return NULL;

    //加载xml
    xml_node *root = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);
    //关闭文件
    fclose(fp);

    return root;
}

//保存xml文件
void xml_save(xml_node *node, const char *path)
{
    //有待实现...
}
