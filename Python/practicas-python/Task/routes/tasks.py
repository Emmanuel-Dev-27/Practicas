from flask import Blueprint, render_template, request, redirect, url_for, flash
from models.task import Group, Step, Substep, db

tasks = Blueprint("tasks", __name__)

@tasks.route('/')
def index():
    groups = Group.query.all()
    return render_template('index.html', groups=groups)


@tasks.route('/new_group', methods=["POST"])
def new_group():
    
    name = request.form["name"]
    
    new_group = Group(name)
    
    db.session.add(new_group)
    db.session.commit()
    
    flash("Create group successfully")
    
    return redirect(url_for("tasks.index"))


@tasks.route('/edit_group/<group_id>', methods=["GET","POST"])
def edit_group(group_id):
    groups = Group.query.all()
    
    group = Group.query.get(group_id)
    
    if request.method == "POST":
        
        name = request.form["name"]
        group.name = name
        db.session.commit()
        
        return redirect(url_for("tasks.index"))
    
    return render_template("edit_group.html", group=group, groups=groups)


@tasks.route('/delete_group/<group_id>')
def delete_group(group_id):
    group = Group.query.get(group_id)
    
    steps = db.session.query(Step).join(Group).filter(Group.id == group_id)
    
    substeps = db.session.query(Substep).join(Step).filter(Step.group_id == group_id).all()
    
    for substep in substeps:
        db.session.delete(substep)
    
    for step in steps:
        db.session.delete(step)
    
    db.session.delete(group)
    db.session.commit()
    
    flash('Group deleted')
    
    return redirect(url_for("tasks.index"))


@tasks.route('/group/<group_id>')
def group(group_id):
    groups = Group.query.all()
    
    steps = db.session.query(Step).join(Group).filter(Group.id == group_id)
    
    substeps = db.session.query(Substep).join(Step).filter(Step.group_id == group_id).all()
    
    return render_template('group.html', group_id=group_id, steps=steps, substeps=substeps, groups=groups)


@tasks.route('/new_step/<group_id>', methods=["POST"])
def new_step(group_id):
    name = request.form["name"]
    
    new_step = Step(name, group_id)
    
    db.session.add(new_step)
    db.session.commit()
    
    flash("Create step successfully")
    
    return redirect(url_for("tasks.group", group_id=group_id))


@tasks.route('/edit_step/<group_id>/<step_id>', methods=["GET", "POST"])
def edit_step(group_id, step_id):
    groups = Group.query.all()
    
    step = Step.query.get(step_id)
    
    if request.method == "POST":
        
        name = request.form["name"]
        step.name = name
        db.session.commit()
        
        return redirect(url_for("tasks.group", group_id=group_id))
    
    return render_template("edit_step.html", step=step, group_id=group_id, groups=groups)


@tasks.route('/delete_step/<group_id>/<step_id>')
def delete_step(group_id, step_id):
    step = Step.query.get(step_id)
    
    substeps = db.session.query(Substep).join(Step).filter(Step.id == step_id)
    
    for substep in substeps:
        db.session.delete(substep)
    
    db.session.delete(step)
    db.session.commit()
    
    flash('Step deleted')
    
    return redirect(url_for("tasks.group", group_id=group_id))


@tasks.route('/new_substep/<group_id>/<step_id>', methods=["POST"])
def new_substep(group_id, step_id):
    name = request.form["name"]
    
    new_substep = Substep(name, step_id)
    
    db.session.add(new_substep)
    db.session.commit()
    
    flash("Create substep successfully")
    
    return redirect(url_for("tasks.group", group_id=group_id))


@tasks.route('/edit_substep/<group_id>/<step_id>/<substep_id>', methods=["GET", "POST"])
def edit_substep(group_id, step_id, substep_id):
    groups = Group.query.all()
    
    substep = Substep.query.get(substep_id)
    
    if request.method == "POST":
        
        name = request.form["name"]
        substep.name = name
        db.session.commit()
        
        return redirect(url_for("tasks.group", group_id=group_id))
    
    return render_template("edit_substep.html", substep=substep, group_id=group_id, step_id=step_id, groups=groups)


@tasks.route('/delete_substep/<group_id>/<step_id>/<substep_id>')
def delete_substep(group_id, step_id, substep_id):
    substep = Substep.query.get(substep_id)
    
    db.session.delete(substep)
    db.session.commit()
    
    flash('Substep deleted')
    
    return redirect(url_for("tasks.group", group_id=group_id))