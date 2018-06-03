mo=read.csv(choose.files())
key=data.frame(val=800)

fit=lm(temp ~ val,mo)
predict(fit,key)

predict(fit)
newcar = data.frame(val=450)
predict(fit, newcar)
ggplot(mo,mapping = aes(mo$val,mo$temp))+geom_point()+geom_smooth(method="lm")
