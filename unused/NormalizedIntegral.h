double NormalizedIntegral(RooAbsPdf * function, RooRealVar& integrationVar, double lowerLimit, double upperLimit)
{
    integrationVar.setRange("integralRange", lowerLimit, upperLimit);
    RooAbsReal* integral = (*function).createIntegral(integrationVar, NormSet(integrationVar), Range("integralRange"));
    double normalizedIntegralValue = integral->getVal();
    return normalizedIntegralValue;
}
