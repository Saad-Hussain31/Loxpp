
#include <iostream>
#include <vector>
#include <any>
#include "Token.hpp"

using namespace lox::interpreter;

class AssignExpr;
class BinaryExpr;
class CallExpr;
class GroupingExpr;
class LogicalExpr;
class LiteralExpr;
class UnaryExpr;
class VarExpr;
class GetExpr;
class SetExpr;
class SuperExpr;
class ThisExpr;




class Expr {
public:
    template <typename R>
    class Visitor {
    public:
        virtual R visit_assign_expr(const AssignExpr& expr) = 0;
        virtual R visit_binary_expr(const BinaryExpr& expr) = 0;
        virtual R visit_call_expr(const CallExpr& expr) = 0;
        virtual R visit_grouping_expr(const GroupingExpr& expr) = 0;
        virtual R visit_logical_expr(const LogicalExpr& expr) = 0;
        virtual R visit_literal_expr(const LiteralExpr& expr) = 0;
        virtual R visit_unary_expr(const UnaryExpr& expr) = 0;
        virtual R visit_var_expr(const VarExpr& expr) = 0;
        virtual R visit_get_expr(const VarExpr& expr) = 0;
        virtual R visit_set_expr(const VarExpr& expr) = 0;
        virtual R visit_super_expr(const VarExpr& expr) = 0;
        virtual R visit_this_expr(const VarExpr& expr) = 0;
    };

    virtual ~Expr() {}
    virtual std::any accept(Visitor<std::any>& visitor) = 0;
};