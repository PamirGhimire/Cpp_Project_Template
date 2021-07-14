#ifndef Widget_H_
#define Widget_H_

namespace WidgetNamespace
{

class Widget
{
  public:
    Widget();
    void Step() const;
    void SetVal(const int val);
    int GetVal() const;
    void Show() const;
  private:
    int val_{-1};
};

} // namespace WidgetNamespace

#endif //Widget_H_