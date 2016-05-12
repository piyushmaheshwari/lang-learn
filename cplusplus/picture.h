#include <iostream>
#include <vector>
#include <string>

class Pic_base {
  friend std::ostream& operator<<(std::ostream&, const Picture&);

  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;

  virtual wd_sz width () const = 0;
  virtual ht_sz height () const = 0;
  virtual void display (std::ostream&, ht_sz, bool) const = 0;

 public:
  virtual ~Pic_base () { }
};

class String_Pic: public Pic_base {
  friend class Picture;
  std::vector<std::string> data;
  String_Pic (const std::vector<std::string>& v): data (v) { }

  wd_sz width () const;
  ht_sz height () const;
  void display (std::ostream&, ht_sz, bool) const;
};

class Frame_Pic: public Pic_base {
  friend Picture frame (const Picture&);
  Ptr<Pic_base> p;
  Frame_pic (const Ptr<Pic_base>& pic): p(pic) { }

  wd_sz width () const;
  ht_sz height () const;
  void display (std::ostream&, ht_sz, bool) const;
};

class VCat_Pic: public Pic_base {
  friend Picture vcat (const Picture&, const Picture&);

  Ptr<Pic_base> top, bottom;
  VCat_Pic (const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top (t), bottom (b) { }

  wd_sz width () const;
  ht_sz height () const;
  void display (std::ostream&, ht_sz, bool) const;
};

class HCat_Pic: public Pic_base {
  friend Picture hcat (const Picture&, const Picture&);

  Ptr<Pic_base> left, right;
  HCat_Pic (const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left (l), right (r) { }

  wd_sz width () const;
  ht_sz height () const;
  void display (std::ostream&, ht_sz, bool) const;
};

class Picture {

  friend Picture frame (const Picture&);
  friend Picture hcat (const Picture&, const Picture&);
  friend Picture vcat (const Picture&, const Picture&);
  friend std::ostream& operator<<(std::ostream&, const Picture&);

 public:
  Picture (const std::vector<std::string>& =
           std::vector<std::string> ()): p (new String_Pic (v)) { }
 private:
  Ptr <Pic_base> p;
  Picture (Pic_base* ptr): p (ptr) { }
}

Picture frame (const Picture&);
Picture hcat (const Picture&, const Picture&);
Picture vcat (const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);
