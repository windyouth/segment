#ifndef _XML_H_
#define _XML_H_

/*
 * author: heluan
 */

#include <mxml.h>

typedef mxml_node_t xml_node;

//加载xml文件
xml_node *xml_load(const char *path);
//保存xml文件
void xml_save(xml_node *node, const char *path);

//创建一个新的节点
#define xml_create(parent, name)    mxmlNewElement(parent, name)
//删除节点
#define xml_delete(node)    mxmlDelete(node)

//寻找子节点
#define xml_sub(root, node, name)   mxmlFindElement(node, root, name, NULL, NULL, MXML_DESCEND)
//读取属性
#define xml_attr(node, key)     mxmlElementGetAttr(node, key)
//读取值
#define xml_value(node)     (node->child->value.text.string)

#endif //_XML_H_
