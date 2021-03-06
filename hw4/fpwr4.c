static float u2f(unsigned u){
  union{
    unsigned a;
    float f;
  } st;
  st.f = 0;
  st.a = u;
  return st.f;
}

float fpwr4(int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;

  if(x < - 74){
    /* Too small. Return 0.0 */
    exp = 0;
    frac = 0;
  } else if (x < -63){
    /* Denormalized result */
    exp = 0;
    frac = 1 << (x*2 +149);
  }
  else if(x < 64){
    /* Normalized Result. */
    exp = 2*x + 127;
    frac = 0;
  }
  else{
    /* Too big.Return +inf*/
    exp = 255;
    frac = 0;
  }
  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
