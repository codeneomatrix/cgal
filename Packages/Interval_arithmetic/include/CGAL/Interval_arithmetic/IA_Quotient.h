// ============================================================================
//
// Copyright (c) 1999,2000 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------------
//
// release       :
// release_date  :
//
// file          : include/CGAL/Interval_arithmetic/IA_Quotient.h
// revision      : $Revision$
// revision_date : $Date$
// package       : Interval Arithmetic
// author(s)     : Sylvain Pion
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec@sophia.inria.fr>)
//
// ============================================================================

#ifndef CGAL_IA_QUOTIENT_H
#define CGAL_IA_QUOTIENT_H

CGAL_BEGIN_NAMESPACE

// We don't know anything about the internal RT type, so there is a risk of
// overflow, but we can't do better than the following trivial conversion.

#if 0
template <class RT>
Interval_base
to_interval (const Quotient<RT> & z)
{
  return Interval_nt<>(CGAL::to_interval(z.numerator())) /
	 Interval_nt<>(CGAL::to_interval(z.denominator()));
}
#endif

template <class RT>
Interval_nt_advanced
convert_from_to (const Interval_nt_advanced&, const Quotient<RT> & z)
{
	CGAL_expensive_assertion(FPU_empiric_test() == CGAL_FE_UPWARD);
	return  convert_from_to(Interval_nt_advanced(), z.numerator()) /
		convert_from_to(Interval_nt_advanced(), z.denominator());
}

#ifndef CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION
template <class RT>
struct converter<Interval_nt_advanced,Quotient<RT> >
{
    static inline Interval_nt_advanced do_it (const Quotient<RT> & z)
    {
	return convert_from_to(Interval_nt_advanced(), z);
    }
};
#endif // CGAL_CFG_NO_PARTIAL_CLASS_TEMPLATE_SPECIALISATION

CGAL_END_NAMESPACE

#endif // CGAL_IA_QUOTIENT_H
