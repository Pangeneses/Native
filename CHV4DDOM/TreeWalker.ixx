module;

#include <string>

export module CHV4DXML:TreeWalker;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
    class TreeWalker
    {
    public:
        TreeWalker() = default;

    public:
        virtual INode root() = 0;
        
        virtual uint32_t whatToShow() = 0;
        
        virtual INodeFilter filter() = 0;
        
        virtual INode currentNode() = 0; 
        virtual void currentNode(INode node) = 0; 
        
        virtual INode ParentNode() = 0;
        
        virtual INode FirstChild() = 0;
        
        virtual INode LastChild() = 0;
        
        virtual INode PreviousSibling() = 0;
        
        virtual INode NextSibling() = 0;
        
        virtual INode PreviousNode() = 0;
        
        virtual INode NextNode() = 0;

    public:
        virtual ~TreeWalker() = 0;

    };

}